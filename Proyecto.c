//system ("dot -Tjpg prueba.dot -o pruebasdsa.jpg");
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include "Cuadros.h"
#include "Arboles.h"
#include "Principal.h"

ArbolBinario Arbol;
void F_insertar (int j)
{
        int nn=0;
        FILE *Archivo;
        Archivo=fopen("graficos.dot","w");                                  
        fprintf (Archivo,"Digraph G {\n");       
        //printf ("inserte un numero \n");                        
        //scanf("%d",&j);
        CuentaNodos(Arbol,&nn);                           
                if(nn==0)
                 {
                   NuevoArbol(&Arbol,NULL,j,NULL);                                              
                  } 
                else
                    {
                    if (Buscar(Arbol,j)==0&&Profundidad(Arbol)<6)                                       
                         {
                              Insertar(&Arbol,j);
                            }
                     else
                        {
                          printf ("\nYa no se puede insertar elementos\n\n");       
                         } 
                    }                    
        grafica(Arbol,-9999,Archivo);                     
        fprintf(Archivo,"}");               
        fclose(Archivo);
        system (" dot -Tjpg graficos.dot -o graficos_prueb.jpg");                                       
}
void F_Eliminar ()
{
        int j;
        FILE *Archivo; 
        printf ("\n");                 
        Archivo=fopen("graficos.dot","w+");
        printf ("Escriba elemento a Eliminar\n");
        fprintf (Archivo,"Digraph G {\n");
        scanf ("%d",&j);
        if (Buscar(Arbol,j)==0)
            printf ("NO HAY ELEMENTOS\n");
        else if (Buscar(Arbol,j)==j)        
                 {
                  Elimina_Elemento(&Arbol,j);        
                  }
             else
                 printf ("\nEl elemento NO EXISTE\n"); 
grafica(Arbol,-9999,Archivo);                                
fprintf(Archivo,"}");
fclose(Archivo);
system (" dot -Tjpg graficos.dot -o graficos_prueb.jpg");
}

void Buscar_Elemento (ArbolBinario Arbol) 
{       
           int j;
        printf ("\n");
        printf ("Numero que desea buscar ");
        scanf ("%d",&j);
        if (Buscar(Arbol,j)==0)
            printf ("NO HAY ELEMENTOS\n");                           
           else if (Buscar(Arbol,j)==j)
                    printf ("\nEl elemento SI EXISTE\n"); 
                else
                     printf ("NO EXISTE EL ELEMENTO\n");                         
}
void grafica (ArbolBinario Arbol,int x,FILE *graficos)
{
	if (Arbol)
	{
	  if(x==-9999)
	    {
	      printf("%d;\n",Arbol->dato);
	      fprintf(graficos,"%d [shape=tripleoctagon,sides=8,peripheries=3,color=cadetblue,fillcolor=darkorange,style=dotted];\n",Arbol->dato);
            }
	  else
	      {
        	printf("%d -> %d;\n",x,Arbol->dato);
	        fprintf(graficos,"%d ->%d [color=red,arrowhead=vee,arrowsize=val,margin=5];\n",x,Arbol->dato);
	        }
        grafica (Arbol->izq,Arbol->dato,graficos);
	grafica (Arbol->der,Arbol->dato,graficos);
	}		
}

void salir ()
{
        exit (1);               
}
