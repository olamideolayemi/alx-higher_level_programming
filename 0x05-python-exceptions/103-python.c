#include <Python.h>
#include <stdio.h>

/**
 * print_python_list - prints some info about python lists
 * @p: pyobject
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t size = 0;
	PyObject *item;

	int i = 0;

	fflush(stdout);
	printf("[*] Python list info\n");
	if (PyList_CheckExact(p))
	{
		item = PyList_GET_ITEM(p, i);
		printf("Element %d: %s\n", i, item->ob_type->tp_name);
		if (PyBytes_Check(item))
			print_python_bytes(item);
		else if (PyFloat_Check(item))
			print_python_float(item);
		i++;
	}
	else
		printf(" [ERROR] Invalid List Object\n");
}

/**
 * print_python_float - prints info about python flaot
 * @p: the pyobject
 */
void print_python_float(PyObject *p)
{
	double val = 0;
	char *string = NULL;

	fflush(stdout);
	printf("[.] float object info\n");

	if (!PyFloat_CheckExact(p))
	{
		printf(" [ERROR] Invalid Flaot Object\n");
		return;
	}
	val = ((PyFloatObject *)p)->ob_fval;
	staring = PyOS_double_to_string(val, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
	printf(" value: %s\n", string);
}

/**
 * print_python_bytes - prints info about python bytes
 * @p: pyobject
 */
void print_python_bytes(PyObject *p)
{
	Py_ssize_t size = 0, i = 0;
	char *string = NULL;

	fflush(stdout);
	printf("[.] bytes object info\n");

	if (!PyBytes_CheckExact(p))
	{
		printf(" [ERROR] Invalid Bytes Object\n");
		return;
	}
	size = PyBytes_Size(p);
	printf(" size: %zd\n", size);
	string = (assert(PyBytes_Check(p)), (((PyBytesObject *)(p))->ob_sval));
	printf(" trying string: %s\n", string);
	printf(" first %zd bytes:", size < 10 ? size + 1 : 10);
	while (i < size + 1 && i < 10)
	{
		printf(" %02hhx", string[i]);
		i++;
	}
	printf("\n");
}
