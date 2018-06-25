# include<python.h> 
#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <utility>
using namespace std;
int main (void)
{
 Py_Initialize();

 PyObject * pModule = NULL;
 PyObject * pFunc   = NULL;

 pModule = PyImport_ImportModule("D:\\◊¿√Ê\\±‡≥Ã¡∑œ∞\\python≈¿≥Ê¡∑œ∞\\");
 pFunc   = PyObject_GetAttrString(pModule, "Hello");
 PyEval_CallObject(pFunc, NULL);

 Py_Finalize();

 return 0;
}



