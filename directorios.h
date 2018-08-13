#ifndef DIRECTORIOS_H
#define DIRECTORIOS_H
#include"virtualdisk.h"
class Directorios
{
private:
    char nombre_[20];
    char nuevo_disco[20];
    const char *elia = "/";
    char nuevo_directorio[20];
    char nombre_eliminar[20];
    const char* file_system = "***File System***\n";
    const char* nombre_disco = "Disco : ";
    const char *directorio_actual = "Directorio actual :";
    const char *creacion_directorio = "***Creacion de directorio***\n";
    const char *ingrese_nombre = "Ingrese nombre : \n";
    const char *lista_directorios = "Los directorios creados son :\n";
    const char *eliminar = "Que directorio desea eliminar :\n";
    char nombre_directorio[20];
    VirtualDisk virtualdisk;
public:
    void Crear_Directorio(char *nombre);
    void Cambiar_Directorio();
    void Listar_Directorios();
    void Eliminar_Directorio();
};

#endif // DIRECTORIOS_H
