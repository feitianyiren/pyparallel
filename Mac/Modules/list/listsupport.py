# This script generates a Python interface for an Apple Macintosh Manager.
# It uses the "bgen" package to generate C code.
# The function specifications are generated by scanning the mamager's header file,
# using the "scantools" package (customized for this particular manager).

import string

# Declarations that change for each manager
MACHEADERFILE = 'Lists.h'		# The Apple header file
MODNAME = '_List'				# The name of the module
OBJECTNAME = 'List'			# The basic name of the objects used here
KIND = 'Handle'				# Usually 'Ptr' or 'Handle'

# The following is *usually* unchanged but may still require tuning
MODPREFIX = 'List'			# The prefix for module-wide routines
OBJECTTYPE = "ListHandle"		# The C type used to represent them
OBJECTPREFIX = MODPREFIX + 'Obj'	# The prefix for object methods
INPUTFILE = string.lower(MODPREFIX) + 'gen.py' # The file generated by the scanner
OUTPUTFILE = MODNAME + "module.c"	# The file generated by this program

from macsupport import *

# Create the type objects
ListHandle = OpaqueByValueType("ListHandle", "ListObj")
ListRef = ListHandle # Obsolete, but used in Lists.h
Cell = Point
ListBounds = Rect
ListBounds_ptr = Rect_ptr
VarOutBufferShortsize = VarHeapOutputBufferType('char', 'short', 's')	# (buf, &len)
InBufferShortsize = VarInputBufferType('char', 'short', 's')		# (buf, len)

RgnHandle = OpaqueByValueType("RgnHandle", "ResObj")
DataHandle = OpaqueByValueType("DataHandle", "ResObj")
Handle = OpaqueByValueType("Handle", "ResObj")
CGrafPtr = OpaqueByValueType("CGrafPtr", "GrafObj")

includestuff = includestuff + """
#ifdef WITHOUT_FRAMEWORKS
#include <Lists.h>
#else
#include <Carbon/Carbon.h>
#endif

#ifdef USE_TOOLBOX_OBJECT_GLUE
extern PyObject *_ListObj_New(ListHandle);
extern int _ListObj_Convert(PyObject *, ListHandle *);

#define ListObj_New _ListObj_New
#define ListObj_Convert _ListObj_Convert
#endif

#if !ACCESSOR_CALLS_ARE_FUNCTIONS
#define GetListPort(list) ((CGrafPtr)(*(list))->port)
#define GetListVerticalScrollBar(list) ((*(list))->vScroll)
#define GetListHorizontalScrollBar(list) ((*(list))->hScroll)
#define GetListActive(list) ((*(list))->lActive)
#define GetListClickTime(list) ((*(list))->clikTime)
#define GetListRefCon(list) ((*(list))->refCon)
#define GetListDefinition(list) ((*(list))->listDefProc) /* XXX Is this indeed the same? */
#define GetListUserHandle(list) ((*(list))->userHandle)
#define GetListDataHandle(list) ((*(list))->cells)
#define GetListFlags(list) ((*(list))->listFlags)
#define GetListSelectionFlags(list) ((*(list))->selFlags)
#define SetListViewBounds(list, bounds) (((*(list))->rView) = *(bounds))

#define SetListPort(list, port) (((*(list))->port) = (GrafPtr)(port))
#define SetListCellIndent(list, ind) (((*(list))->indent) = *(ind))
#define SetListClickTime(list, time) (((*(list))->clikTime) = (time))
#define SetListLastClick(list, click) (((*(list)->lastClick) = *(click))
#define SetListRefCon(list, refcon) (((*(list))->refCon) = (refcon))
#define SetListUserHandle(list, handle) (((*(list))->userHandle) = (handle))
#define SetListFlags(list, flags) (((*(list))->listFlags) = (flags))
#define SetListSelectionFlags(list, flags) (((*(list))->selFlags) = (flags))

#endif

#define as_List(x) ((ListHandle)x)
#define as_Resource(lh) ((Handle)lh)
"""

initstuff = initstuff + """
	PyMac_INIT_TOOLBOX_OBJECT_NEW(ListHandle, ListObj_New);
	PyMac_INIT_TOOLBOX_OBJECT_CONVERT(ListHandle, ListObj_Convert);
"""

class ListMethodGenerator(MethodGenerator):
	"""Similar to MethodGenerator, but has self as last argument"""

	def parseArgumentList(self, args):
		args, a0 = args[:-1], args[-1]
		t0, n0, m0 = a0
		if m0 != InMode:
			raise ValueError, "method's 'self' must be 'InMode'"
		self.itself = Variable(t0, "_self->ob_itself", SelfMode)
		FunctionGenerator.parseArgumentList(self, args)
		self.argumentList.append(self.itself)

getattrHookCode = """{
	/* XXXX Should we HLock() here?? */
	if ( strcmp(name, "listFlags") == 0 )
		return Py_BuildValue("l", (long)(*self->ob_itself)->listFlags & 0xff);
	if ( strcmp(name, "selFlags") == 0 )
		return Py_BuildValue("l", (long)(*self->ob_itself)->selFlags & 0xff);
}"""

setattrCode = """
static int
ListObj_setattr(ListObject *self, char *name, PyObject *value)
{
	long intval;
		
	if ( value == NULL || !PyInt_Check(value) )
		return -1;
	intval = PyInt_AsLong(value);
	if (strcmp(name, "listFlags") == 0 ) {
		/* XXXX Should we HLock the handle here?? */
		(*self->ob_itself)->listFlags = intval;
		return 0;
	}
	if (strcmp(name, "selFlags") == 0 ) {
		(*self->ob_itself)->selFlags = intval;
		return 0;
	}
	return -1;
}
"""


class MyObjectDefinition(GlobalObjectDefinition):

	def outputStructMembers(self):
		ObjectDefinition.outputStructMembers(self)
		Output("int ob_must_be_disposed;")

	def outputCheckNewArg(self):
		Output("""if (itself == NULL) {
					PyErr_SetString(List_Error,"Cannot create null List");
					return NULL;
				}""")
				
	def outputInitStructMembers(self):
		ObjectDefinition.outputInitStructMembers(self)
		Output("it->ob_must_be_disposed = 1;")

	def outputFreeIt(self, itselfname):
		Output("if (self->ob_must_be_disposed && %s) LDispose(%s);", itselfname, itselfname)
		
	def outputGetattrHook(self):
		Output(getattrHookCode)
		
	def outputSetattr(self):
		Output(setattrCode)
		
# From here on it's basically all boiler plate...

# Create the generator groups and link them
module = MacModule(MODNAME, MODPREFIX, includestuff, finalstuff, initstuff)
object = MyObjectDefinition(OBJECTNAME, OBJECTPREFIX, OBJECTTYPE)
module.addobject(object)

# Create the generator classes used to populate the lists
Function = FunctionGenerator
Method = ListMethodGenerator

# Create and populate the lists
functions = []
methods = []
execfile(INPUTFILE)

# Function to convert any handle to a list and vv.
##f = Function(ListHandle, 'as_List', (Handle, 'h', InMode))
as_List_body = """
Handle h;
ListObject *l;
if (!PyArg_ParseTuple(_args, "O&", ResObj_Convert, &h))
	return NULL;
l = (ListObject *)ListObj_New(as_List(h));
l->ob_must_be_disposed = 0;
return Py_BuildValue("O", l);
"""
f = ManualGenerator("as_List", as_List_body)
f.docstring = lambda: "(Resource)->List.\nReturns List object (which is not auto-freed!)"
functions.append(f)

f = Method(Handle, 'as_Resource', (ListHandle, 'lh', InMode))
methods.append(f)

# add the populated lists to the generator groups
# (in a different wordl the scan program would generate this)
for f in functions: module.add(f)
for f in methods: object.add(f)

# generate output (open the output file as late as possible)
SetOutputFileName(OUTPUTFILE)
module.generate()

