#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#include <gtk/gtk.h>
//#include "Cuadros.h"
#include "Arboles.h"
#include "Arbol.h"
#include "Proyecto.h"

void Arbol1(int argc, char *argv[])
{

	gtk_init (&argc, &argv);//Se inicia el modo gtk
	// Se crea la ventana principal VPrincipal.
	VPrincipal = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	// Le ponemos nombre a la ventana.
	gtk_window_set_title (GTK_WINDOW (VPrincipal), "Árboles");
	// Deja la ventana estatica.
	gtk_window_set_resizable(GTK_WINDOW(VPrincipal),FALSE);
	// Definimos la dimencion de la ventana.
	gtk_widget_set_size_request (VPrincipal,1366 , 768);
	// Pocionamos la ventana siempre en el centro de la pantalla.
	gtk_window_set_position(GTK_WINDOW(VPrincipal), GTK_WIN_POS_CENTER);
	// Inicializamos el contenedor.
	marco=gtk_fixed_new(); // se declara dentro de donde va a quedar la imagen 
	// Se agrega la ventana al marco.
	gtk_container_add (GTK_CONTAINER(VPrincipal),marco);
	//imagenes de fondo
	fondo=gtk_image_new_from_file("fondo.png");
	gtk_fixed_put(GTK_FIXED(marco),fondo,-28,-70);
	//crea el icono del programa
	gtk_window_set_icon(GTK_WINDOW(VPrincipal), create_pixbuf("C.jpg"));
	
	//crea las cajas de texto 
	
	int tamagno=50;
	
	caja_Insertar=gtk_entry_new();
	gtk_fixed_put (GTK_FIXED (marco),caja_Insertar,1180,tamagno+10);
	gtk_widget_set_size_request(caja_Insertar, 145,50);
	
	
	caja_Eliminar=gtk_entry_new();
	gtk_fixed_put (GTK_FIXED (marco),caja_Eliminar,1180,tamagno+200);
	gtk_widget_set_size_request(caja_Eliminar, 145,50);
	
	
	//crea los botones
	
	Inserta= gtk_button_new_with_label("            Insertar           ");//boton para Insertar nuevos nodos 
	gtk_fixed_put (GTK_FIXED (marco),Inserta,1183,150);
	InsertarI=gtk_image_new_from_file("Insert.png");
	gtk_fixed_put(GTK_FIXED(marco),InsertarI,500,135);
	Elimina= gtk_button_new_with_label("           Eliminar          ");//boton para Eliminar nodos existentes
	gtk_fixed_put (GTK_FIXED (marco),Elimina,1184,340);
	EliminarI=gtk_image_new_from_file("ELIM.png");
	gtk_fixed_put(GTK_FIXED(marco),EliminarI,1180,325);
	
	//Acciones de los botones
	
	g_signal_connect (G_OBJECT (Inserta), "clicked",G_CALLBACK (Inserta_nodos),NULL);
	g_signal_connect (G_OBJECT (Elimina), "clicked",G_CALLBACK (Elimina_nodos),NULL);


	/*Acerca= gtk_button_new_with_label("Acerca de...");//boton para la ventana de programadores
	gtk_fixed_put (GTK_FIXED (marco),Acerca,150,10);	
	g_signal_connect (G_OBJECT (Acerca), "clicked",G_CALLBACK (AcercaD), NULL);
	//al darle click a la funcion de programadores te manda a la ventana de AcercaD*/
	
	gtk_widget_show_all(VPrincipal);//pone en pantalla todo lo que hay en la ventana principal
	gtk_main();// Se cierra el modo gtk

}

void Inserta_nodos(GtkWidget *widget, gpointer datos)
{
printf("1");
//	int v,t,n;//Variable que almacena el valor retornado por la función Verifica_Numero
//	char numero[50];
//	const gchar *Insert;
//	Insert=gtk_entry_get_text(GTK_ENTRY(caja_Insertar));
//	strcpy(numero,Insert);
//	t=strlen(numero);
//	n=atoi(Insert);
//	if (t==0)
//		mostrar_advertencia("No ha introducido ningún elemento\n Intente de nuevo",VPrincipal);
//	else
//	    {
//		v=Verifica_Numero(numero);
//		if (v==0)
//		  {
//			gtk_entry_set_text(GTK_ENTRY(caja_Insertar),"");
//			F_insertar(n);
//		  }
//		else
//	   	    {
//			mostrar_error("Elemento no valido\n Intente de nuevo",VPrincipal);
//			gtk_entry_set_text(GTK_ENTRY(caja_Insertar),"");
//	   	    }
//	    }
}

void Elimina_nodos(GtkWidget *widget, gpointer datos)
{
	int v,t;//Variable que almacena el valor retornado por la función Verifica_Numero
	char numero[50];
	const gchar *Elim;
	Elim=gtk_entry_get_text(GTK_ENTRY(caja_Eliminar));
	strcpy(numero,Elim);
	t=strlen(numero);
	if (t==0)
		mostrar_advertencia("No ha introducido ningún elemento\n Intente de nuevo",VPrincipal);
	else
	    {
		v=Verifica_Numero(numero);
		if (v==0)
			gtk_entry_set_text(GTK_ENTRY(caja_Eliminar),"");
		else
	     	{
			mostrar_error("Elemento no valido\n Intente de nuevo",VPrincipal);
			gtk_entry_set_text(GTK_ENTRY(caja_Eliminar),"");
	     	}
	    }
}

int Verifica_Numero(char numero[50])
{
	int k=0,sw=0,j;
	//char numero[50];
	j=strlen(numero); // cuenta la cantidad de caracteres que hay dentro de una cadena
	while(k<j && sw==0)
	{
		if(isdigit(numero[k])!=0)
			k++;
		else
			sw=1;
	}
	if (sw==0)
		printf("%s es dígito\n",numero);
	else
		printf("%s no es dígito\n",numero);
	return sw;
}

// Para la creacion del icono del programa 
GdkPixbuf *create_pixbuf(const gchar * filename)
 {
    GdkPixbuf *pixbuf;
    GError *error = NULL;
    pixbuf = gdk_pixbuf_new_from_file(filename, &error);
    if(!pixbuf) {
       fprintf(stderr, "%s\n", error->message);
       g_error_free(error);
    }

    return pixbuf;
 }
