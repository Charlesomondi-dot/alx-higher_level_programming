#!/usr/bin/python3

void print_python_list(PyObject *p) {
Py_ssize_t size, i;
PyObject *item;

if (!PyList_Check(p)) {
fprintf(stderr, "Invalid Python list\n");
return;
}

size = PyList_Size(p);
printf("[*] Python list info\n");
printf("[*] Size of the Python List = %ld\n", size);
printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

for (i = 0; i < size; ++i) {
item = PyList_GetItem(p, i);
printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
}
}

void print_python_bytes(PyObject *p) {
Py_ssize_t size, i;
char *str;

if (!PyBytes_Check(p)) {
fprintf(stderr, "[ERROR] Invalid Bytes Object\n");
return;
}

size = PyBytes_Size(p);
str = PyBytes_AsString(p);

printf("[.] bytes object info\n");
printf("  size: %ld\n", size);
printf("  trying string: %s\n", str);

if (size > 10) {
size = 10;
}

printf("  first %ld bytes:", size);
for (i = 0; i < size; ++i) {
printf(" %02hhx", str[i]);
}
printf("\n");
}

