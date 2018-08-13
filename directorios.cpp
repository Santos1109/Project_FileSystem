#include "directorios.h"

void Directorios::Crear_Directorio(char *nombre)
{
    printf(creacion_directorio);
    printf(nombre_disco);
    cout<<nombre<<endl;
    strcpy(nuevo_disco,nombre);
    printf(directorio_actual);
    cout<<virtualdisk.DirectorioActual()<<endl;
    printf(ingrese_nombre);
    cin>>nombre_;
    strcpy(nombre_directorio,nombre_);
    char *temp = nombre_directorio;
    virtualdisk.salida.write(temp,virtualdisk.getPosicionBloqueActual());
    virtualdisk.Asignar_file_entry_directorio();
}
void Directorios::Cambiar_Directorio()
{
    printf(nombre_disco);
    cout<<nuevo_disco<<endl;
    printf(directorio_actual);
    cout<<nombre_directorio<<endl;
    virtualdisk.salida.seekp(0,ios::end);
    cout<<"Escriba el directorio que se desea cambiar : "<<endl;
    cin>>nuevo_directorio;
    strcpy(nombre_,nuevo_directorio);
    virtualdisk.salida.write(nuevo_directorio,virtualdisk.getPosicionDirectorioActual());
    virtualdisk.Asignar_file_entry_directorio();
}
void Directorios::Listar_Directorios()
{
    printf(this->lista_directorios);
    ifstream leer(this->nuevo_disco,ios::in|ios::binary);
    for(int i=virtualdisk.Tamano_file_entry_directorio()+53;i<virtualdisk.Tamano_file_entry_directorio();i++)
    {
        leer.read(this->nombre_,i);
        cout<<this->nombre_<<endl;
    }
}
void Directorios::Eliminar_Directorio()
{
    ifstream leer(this->nuevo_disco,ios::in|ios::binary);
    while(!leer.eof())
    {
        cout<<"Ingrese el nombre del directorio que desea eliminar : "<<endl;
        cin>>nombre_eliminar;
        if(nombre_eliminar==this->nombre_)
        {
           leer.read(nombre_eliminar,virtualdisk.Tamano_file_entry_directorio());
           strcpy(nombre_,this->elia);
       }
    }
}
