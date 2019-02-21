#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include "Cuadros.h"
#include "Arboles.h"
//#include "Proyecto.h"

GtkWidget *ventana_principal,*marco,*marco2,*fondo,*Acerca;
GtkWidget *Title,*Menu,*CA,*Help,*AD,*Salir;
GdkColor color;
PangoFontDescription *fuente;

void Inserta_nodos(GtkWidget *widget, gpointer datos);
void Elimina_nodos(GtkWidget *widget, gpointer datos);
int Verifica_Numero(char numero[50]);
//GdkPixbuf *create_pixbuf(const gchar * filename);
static void destroy( GtkWidget *widget,gpointer   data )
{
    gtk_main_quit ();
}

int main (int argc, char *argv[])
{

	gtk_init (&argc, &argv);//Se inicia el modo gtk
	// Se crea la ventana principal ventana_principal.
	ventana_principal = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	// Le ponemos nombre a la ventana.
	gtk_window_set_title (GTK_WINDOW (ventana_principal), "Árboles");
	// Deja la ventana estatica.
	gtk_window_set_resizable(GTK_WINDOW(ventana_principal),FALSE);
	// Definimos la dimencion de la ventana.
	gtk_widget_set_size_request (ventana_principal,1366 , 768);
	// Pocionamos la ventana siempre en el centro de la pantalla.
	gtk_window_set_position(GTK_WINDOW(ventana_principal), GTK_WIN_POS_CENTER);
	// Inicializamos el contenedor.
	marco=gtk_fixed_new(); // se declara dentro de donde va a quedar la imagen 
	// Se agrega la ventana al marco.
	gtk_container_add (GTK_CONTAINER(ventana_principal),marco);
	//imagenes de fondo
	fondo=gtk_image_new_from_file("fondo.png");
	gtk_fixed_put(GTK_FIXED(marco),fondo,-28,-70);
	//crea el icono del programa
	//gtk_window_set_icon(GTK_WINDOW(ventana_principal), create_pixbuf("Egipto.jpg"));

	//Imagen de titulo
	Title=gtk_image_new_from_file("Title.png");
	gtk_fixed_put(GTK_FIXED(marco),Title,500,10);
	
	//crea los botones
	
	CA= gtk_button_new_with_label("   	  	 			  Crear Árbol  		  			  \n\n\n\n");//boton para crear arbol
	gtk_fixed_put (GTK_FIXED (marco),CA,535,250);
	
	Help= gtk_button_new_with_label("	   		 			   Ayuda		 			  \n\n\n\n");//boton para muestra ayuda
	gtk_fixed_put (GTK_FIXED (marco),Help,535,360);
		AD= gtk_button_new_with_label("   	  	 			  Acerca De  		  			  \n\n\n\n");//boton para ir a Acerca De
	gtk_fixed_put (GTK_FIXED (marco),AD,535,465);
	Salir= gtk_button_new_with_label("   	  	 			  		Salir  		  			  \n\n\n\n");//boton para salir del programa
	gtk_fixed_put (GTK_FIXED (marco),Salir,535,565);
	
	
	//Imagen del menu
	Menu=gtk_image_new_from_file("Menu.png");
	gtk_fixed_put(GTK_FIXED(marco),Menu,535,250);
	
	
	
	//Acciones de los botones
	
	g_signal_connect (G_OBJECT (CA), "clicked",G_CALLBACK (Arbol1),NULL);
	//g_signal_connect (G_OBJECT (Eliminar), "clicked",G_CALLBACK (Elimina_nodos),NULL);


	/*Acerca= gtk_button_new_with_label("Acerca de...");//boton para la ventana de programadores
	gtk_fixed_put (GTK_FIXED (marco),Acerca,150,10);	
	g_signal_connect (G_OBJECT (Acerca), "clicked",G_CALLBACK (AcercaD), NULL);
	//al darle click a la funcion de programadores te manda a la ventana de AcercaD*/
	g_signal_connect (G_OBJECT (ventana_principal), "destroy",G_CALLBACK (destroy), NULL);
	gtk_widget_show_all(ventana_principal);//pone en pantalla todo lo que hay en la ventana principal
	gtk_main();// Se cierra el modo gtk
	
	 //conectamos los botones a ventanas correspondientes
	//g_signal_connect(CA,"clicked", G_CALLBACK (ventana_agregar),NULL);
	/*//g_signal_connect(Buscar,"clicked", G_CALLBACK (ventana_actualiza),NULL);
	g_signal_connect(Actualizar,"clicked", G_CALLBACK (ventana_actualiza),NULL);
	g_signal_connect(VerContactos,"clicked", G_CALLBACK (ventana_ver_contactos),NULL);
	g_signal_connect(Borrar,"clicked", G_CALLBACK (ventana_borra),NULL);*/
	//destructor de todo el programa
	//g_signal_connect(ventana_principal,"destroy", G_CALLBACK (gtk_main_quit),NULL);
	//g_signal_connect(Salir,"clicked",G_CALLBACK(cerrar),ventana_principal);

return 0;
}
