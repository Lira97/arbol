#include <iostream>
using namespace std;
#ifndef Arbol_H
#define Arbol_H

class Arbol;

	class nodo 
	{
		private:
		int Info;
		nodo *HijoIzq;
		nodo *HijoDer;
		
		public:
		nodo();
		int RegresaInfo();
		friend class Arbol;
		
	};

nodo::nodo()
{
	HijoDer=NULL;
	HijoIzq=NULL;
}

int nodo::RegresaInfo()
{
	return Info;
}

class Arbol
{
	private:
	nodo *Raiz;
	public:
	Arbol();
	void CrearArbol(nodo *);
	void Preorden(nodo *);
	void Inorden(nodo *);
	void Postorden(nodo *);
	nodo *RegresaRaiz();
};

Arbol::Arbol()
{
	Raiz=NULL;
}

void Arbol::CrearArbol(nodo *Apunt)
{
	char Resp;
	Apunt = new nodo;
	cout<<"Ingrese la informacion a almacenar :";
	cin>>Apunt->Info;
	cout<<"\n\n"<<Apunt->Info<<"Tiene hijo izquierdo (s/n)";
	cin>>Resp;
	if(Resp == 's')
	{
		CrearArbol(Apunt->HijoIzq);
		Apunt->HijoIzq=Raiz;
	}
	cout<<"\n\n"<<Apunt->Info<<"Tiene hijo Derecho (s/n)";
	cin>>Resp;
	 if(Resp == 's')
	{
		CrearArbol(Apunt->HijoDer);
		Apunt->HijoDer=Raiz;
	}
	Raiz=Apunt;
	
}
void Arbol::Preorden(nodo *Apunt)
{
	if (Apunt)
	{
		cout<<Apunt->Info<<" ";
		Preorden(Apunt->HijoIzq);
		Preorden(Apunt->HijoDer);
	}
}
void Arbol::Inorden(nodo *Apunt)
{
	if (Apunt)
	{
		Inorden(Apunt->HijoIzq);
		cout<<Apunt->Info<<" ";
		Inorden(Apunt->HijoDer);
	}
}
void Arbol::Postorden(nodo *Apunt)
{
	if (Apunt)
	{
		Preorden(Apunt->HijoIzq);
		Preorden(Apunt->HijoDer);
		cout<<Apunt->Info<<" ";
	}
}
nodo *Arbol::RegresaRaiz()
{
	return Raiz;
}


#endif