#include <stdio.h>
#include <stdlib.h>

typedef int TipoElemento;

typedef struct nodo
{
	TipoElemento dato;
	struct nodo *izq;
	struct nodo *der;
}nodo;

typedef nodo *ArbolBinario;

void NuevoArbol (ArbolBinario *raiz, ArbolBinario ramaIzq, TipoElemento x, ArbolBinario ramaDer);
ArbolBinario CrearNodo(TipoElemento x);
void PreOrden (ArbolBinario raiz);
void Visitar (TipoElemento x);
void EnOrden (ArbolBinario raiz);
void PostOrden(ArbolBinario raiz);
int Profundidad (ArbolBinario raiz);
int Buscar (nodo *raiz,TipoElemento buscado);
void Insertar (nodo **raiz,TipoElemento dato);
void Elimina_Elemento(nodo **raiz,TipoElemento num);
void Reemplazar(nodo **raiz, nodo **aux);
void CuentaNodos (ArbolBinario raiz,int *tot);

int x;
