#include <iostream>
#include "Arbol.h"

using namespace std;
int main() 
{
	Arbol uno;
	nodo *ap;
	ap =uno.RegresaRaiz();
	uno.CrearArbol(ap);
	cout<<"\n";
	uno.Preorden(ap);
	cout<<"\n";
	uno.Inorden(ap);
	cout<<"\n";
	uno.Postorden(ap);
	
}