#include <Python.h>
#include <stdio.h>

void print_python_list(PyObject *p) {
if (!PyList_Check(p)) {
fprintf(stderr, "Invalid List Object\n");
return;
}

Py_ssize_t size = PyList_Size(p);

printf("[*] Python list info\n");
printf("[*] Size of the Python List = %zd\n", size);
printf("[*] Allocated = %zd\n", ((PyListObject *)p)->allocated);

for (Py_ssize_t i = 0; i < size; ++i) {
printf("Element %zd: %s\n", i, Py_TYPE(PyList_GetItem(p, i))->tp_name);
}
}

void print_python_bytes(PyObject *p) {
if (!PyBytes_Check(p)) {
fprintf(stderr, "Invalid Bytes Object\n");
return;
}

Py_ssize_t size = PyBytes_Size(p);
const char *bytes_str = PyBytes_AsString(p);

printf("[.] bytes object info\n");
printf("size: %zd\n", size);
printf("trying string: %s\n", bytes_str);

printf("first 10 bytes: ");
for (Py_ssize_t i = 0; i < size && i < 10; ++i) {
printf("%02hhx", bytes_str[i]);
if (i + 1 < size && i + 1 < 10) {
printf(" ");
}
}
printf("\n");
}

void print_python_float(PyObject *p) {
if (!PyFloat_Check(p)) {
fprintf(stderr, "Invalid Float Object\n");
return;
}

printf("[.] float object info\n");
printf("value: %lf\n", ((PyFloatObject *)p)->ob_fval);
}

