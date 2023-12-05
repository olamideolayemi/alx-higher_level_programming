#include <stdlib.h>
#include <stdio.h>
#include <Python.h>

/**
 * print_python_list_info - prints some basic info about Python lists
 * @p: python list
 */
void print_python_list_info(PyObject *p)
{
	int i;

	printf("[*] Size of the PythonList = %lu\n", Py_SIZE(p));
	printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);
	for (i = 0; i < Py_SIZE(p); i++)
		printf("Element %d: %s\n", i, Py_TYPE(PyList_GetItem(p, i))->tp_name);
}
