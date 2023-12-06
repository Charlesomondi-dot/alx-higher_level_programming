#include <Python.h>

void print_python_list(PyObject *p) {
Py_ssize_t i, size;
PyObject *element;

	if (!PyList_Check(p)) {
		fprintf(stderr, "[*] Python list info\n  [ERROR] Invalid List Object\n");
	return;
	}

	size = PyList_Size(p);

	printf("[*] Python list info\n[*] Size of the Python List = %ld\n[*] Allocated = %ld\n", size, ((PyListObject *)p)->allocated);
	
	for (i = 0; i < size; ++i) {
		element = PyList_GetItem(p, i);
		printf("Element %ld: %s\n", i, Py_TYPE(element)->tp_name);
		if (PyBytes_Check(element)) {
			printf("[.] bytes object info\n");
			printf("  size: %ld\n", PyBytes_Size(element));
			printf("  trying string: %s\n", PyBytes_AsString(element));
			printf("  first 10 bytes: ");
		for (Py_ssize_t j = 0; j < 10 && j < PyBytes_Size(element); ++j) {
			printf("%02x ", (unsigned char)PyBytes_AsString(element)[j]);
		}
		printf("\n");
	}
	}
	}

void print_python_bytes(PyObject *p) {
Py_ssize_t size;

	if (!PyBytes_Check(p)) {
	fprintf(stderr, "[.] bytes object info\n  [ERROR] Invalid Bytes Object\n");
		return;
	}

	size = PyBytes_Size(p);

	printf("[.] bytes object info\n");
	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", PyBytes_AsString(p));
	printf("  first 10 bytes: ");
	for (Py_ssize_t i = 0; i < 10 && i < size; ++i) {
		printf("%02x ", (unsigned char)PyBytes_AsString(p)[i]);
	}
		printf("\n");
	}
