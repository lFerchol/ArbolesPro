//system ("dot -Tjpg prueba.dot -o pruebasdsa.jpg");
#include <stdio.h>
#include "Arbol.h"
#include <stdlib.h>
void insertar (int i);
void Eliminar ();
void Buscar_Elemento (ArbolBinario Arbol);
void grafica (ArbolBinario Arbol,int x,FILE *graficos);
void salir ();
ArbolBinario Arbol;
int main ()
{
        int i=0;        

        system ("clear");                  
        for (i=0;i<4;i++)       
            insertar(i); 
        printf ("\nORDENAR\n");
        PreOrden (Arbol);
        printf ("\nORDENAR\n");        
        EnOrden (Arbol);
        printf ("\nORDENAR\n");        
        PostOrden (Arbol);
        for (i=0;i<2;i++)
            Eliminar();
        for (i=0;i<2;i++)
             Buscar_Elemento(Arbol);
        salir ();                            
        return 0;                                         
}

void insertar (int i)
{
        int j,nn;
        FILE *Archivo;
        Archivo=fopen("graficos.dot","w");                                  
        fprintf (Archivo,"Digraph G {\n");       
        printf ("inserte un numero \n");                        
        scanf("%d",&j);
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
void Eliminar ()
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
