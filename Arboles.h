#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include "Cuadros.h"
//#include "Arbol.h"
//#include "Proyecto.h"

GtkWidget *VPrincipal,*marco,*marco2,*fondo,*Acerca;
GtkWidget *Inserta, *InsertarI, *Elimina, *EliminarI;
GtkWidget *caja_Insertar, *caja_Eliminar;
GtkWidget *nombres, *Salir, *ima;
GdkColor color;
PangoFontDescription *fuente;

void Arbol1(int argc, char *argv[]);
void Inserta_nodos(GtkWidget *widget, gpointer datos);
void Elimina_nodos(GtkWidget *widget, gpointer datos);
int Verifica_Numero(char numero[50]);
GdkPixbuf *create_pixbuf(const gchar * filename);
//ArbolBinario Arbol;
void F_insertar (int j);
