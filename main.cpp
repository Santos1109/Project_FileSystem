#include <iostream>
#include"virtualdisk.h"
#include"directorios.h"
using namespace std;

int main()
{

   Directorios directorios;
   VirtualDisk virtualdisk;
   //Metadata
   const char *metad_data = "La MetaData del disco es : \n";
   //Menu principal
   const char *marco = "*****************************\n";
   const char *file_system = "****FILE SYSTEM****\n";
   const char *opciones = "1.Crear Disco\n2.Utilizar Disco Existente\n3.Salir\n";
   //Crear Disco
   const char *crear_disco = "Crear Disco\n";
   const char *nombre_disco = "Ingrese nombre del disco :\n";
   char nombredisco[20];
   const char *cantidad_bloques = "Ingrese cantidad de bloques :\n";
   long cantidadbloque;
   const char *cantidad_entradas = "Ingrese cantidad de entradas :\n";
   int cantidadentradas;
   //Utilizar Disco Existente
   const char *crear_directorio = "1 Crear directorio\n";
   const char *cambiar_directorio = "2 Cambiar directorio\n";
   const char *listar_directorio = "3 Listar directorio\n";
   const char *eliminar_directorio = "4 Eliminar directorio\n";
   const char *importar_archivo = "5 Importar archivo\n";
   const char *archivo = "Deme la direccion del archivo que desea guardar : \n";
   const char *exportar_archivo = "6 Exportar archivo\n";
   const char *regresar_ = "7.Regresar\n";
   bool regresar = true;
   char nombre_archivo[20];
   int decision_;
   char uno = opciones[0];
   char dos = opciones[14];
   char tres = opciones[41];
   unsigned char decision;
   bool salir = true;

   do{
       printf(file_system);
        printf(marco);
        printf(opciones);
        printf(marco);
        cin>>decision;
       if(decision==uno)
       {
           printf(crear_disco);//Crear disco
           printf(nombre_disco);//Nombre del disco
           cin>>nombredisco;
           printf(cantidad_entradas);//Cantidad de entradas
           cin>>cantidadentradas;
           printf(cantidad_bloques);//Cantidad de bloques
           cin>>cantidadbloque;
           virtualdisk.Nuevo_disco(nombredisco,cantidadentradas,cantidadbloque);
           virtualdisk.Asignar_file_entry_directorio();
           printf(metad_data);
           virtualdisk.Mostar_MetaData();
       }
       else if(decision==dos)
       {
           do{
           printf(crear_directorio);
           printf(cambiar_directorio);
           printf(listar_directorio);
           printf(eliminar_directorio);
           printf(importar_archivo);
           printf(exportar_archivo);
           printf(regresar_);
           cin>>decision_;

           if(decision_==1)
           {
               directorios.Crear_Directorio(nombredisco);
               cout<<"El directorio ha sido creado!"<<endl;

           }
           else if(decision_==2)
           {
               directorios.Cambiar_Directorio();
               cout<<"Ha cambiado de directorio !"<<endl;
           }
           else if(decision_==3)
           {
               directorios.Listar_Directorios();
               cout<<"Listar directorio con exito!"<<endl;

           }
           else if(decision_==4)
           {
               directorios.Eliminar_Directorio();
               cout<<"Se ha eliminado el directorio"<<endl;

           }
           else if(decision_==5)
           {
               printf(archivo);
               cin>>nombre_archivo;
               virtualdisk.Importar_archivo(nombre_archivo);
               cout<<"Se ha importado el archivo exitosamente !"<<endl;

           }
           else if(decision_==6)
           {

           }
           else if(decision_==7)
           {
               regresar = false;
           }
           }while(regresar);

       }
       else if(decision==tres)
       {
           salir = false;
       }
   }while(salir);
}
