#include <stdio.h>
#include "Arbol.h"

void NuevoArbol (ArbolBinario *raiz, ArbolBinario ramaIzq, TipoElemento x, ArbolBinario ramaDer)
{
	*raiz=CrearNodo(x);
	(*raiz)->izq=ramaIzq;
	(*raiz)->der=ramaDer;
}

ArbolBinario CrearNodo(TipoElemento x)
{
	ArbolBinario a;
	a=(ArbolBinario)malloc(sizeof(nodo));
	a->dato=x;
	a->izq=a->der=NULL;
	return a;
}

void PreOrden (ArbolBinario raiz)
{
	if (raiz){
		Visitar(raiz->dato);
		PreOrden(raiz->izq);
		PreOrden(raiz->der);
	}
}
void CuentaNodos (ArbolBinario raiz,int *tot)
{
	if (raiz){
		*tot=*tot+1;
		CuentaNodos(raiz->izq,tot);
		CuentaNodos(raiz->der,tot);
	}
	x=*tot;
}

void Visitar (TipoElemento x)
{
	printf("%d-->",x);
}

void EnOrden (ArbolBinario raiz)
{
	if(raiz){
		EnOrden(raiz->izq);
		Visitar(raiz->dato);
		EnOrden(raiz->der);
	}
}

void PostOrden(ArbolBinario raiz)
{
	if(raiz){
		PostOrden(raiz->izq);
		PostOrden(raiz->der);
		Visitar(raiz->dato);
	}
}

int Profundidad (ArbolBinario raiz)
{
	int profundidadI,profundidadD;
	if(!raiz)
		return 0;
	else{
		profundidadI=Profundidad(raiz->izq);
		profundidadD=Profundidad(raiz->der);
		if(profundidadI>profundidadD)
			return profundidadI+1;
		else
			return profundidadD+1;
	}
}

int Buscar (nodo *raiz,TipoElemento buscado)
{
	if(!raiz)
		return 0;
	else if(buscado==raiz->dato)
		return raiz->dato;
	else if(buscado<raiz->dato)
		return Buscar(raiz->izq,buscado);
	else
		return Buscar(raiz->der,buscado);
}

void Insertar (nodo **raiz,TipoElemento dato)
{
	if(!(*raiz))
		*raiz=CrearNodo(dato);
	else if(dato<(*raiz)->dato)
		Insertar(&((*raiz)->izq),dato);
	else
		Insertar(&((*raiz)->der),dato);
}

void Elimina_Elemento(nodo **raiz,TipoElemento num)
{
  nodo *aux;
 
  if (*raiz == NULL){
	printf("\nEl árbol está vacio");
    return;
    }
  if ((*raiz)->dato < (num))
    Elimina_Elemento(&(*raiz)->der, num);
  else if ((*raiz)->dato > num)
    Elimina_Elemento(&(*raiz)->izq,num);
  else if ((*raiz)->dato == num)
  {
    aux = *raiz;
    if ((*raiz)->izq== NULL)
      *raiz = (*raiz)->der;
    else if ((*raiz)->der == NULL)
      *raiz = (*raiz)->izq;
    else
      Reemplazar(&(*raiz)->izq, &aux);
 
    free(aux);
  }
}
 
void Reemplazar(nodo **raiz, nodo **aux)
{
  if ((*raiz)->der == NULL)
  {
    (*aux)->dato = (*raiz)->dato;
    *aux = *raiz;
    *raiz = (*raiz)->izq;
  }
  else
    Reemplazar(&(*raiz)->der,aux);
}
