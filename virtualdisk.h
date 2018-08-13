#ifndef VIRTUALDISK_H
#define VIRTUALDISK_H
#include<fstream>
#include<cstring>
#define SINPADRE -1
#include<iostream>

using namespace std;
const int TAMANO_BLOQUES = 1020;
typedef char* byte;
typedef int entero_bytes;
typedef char tamano_bloque[TAMANO_BLOQUES];
typedef short entrada_fat;
typedef entrada_fat bloque_fat;

typedef struct Block
{
    tamano_bloque data;
    int siguiente;

}block_t;

struct FILE_ENTRY
{

char nombre[20];
char tipo;
int tamano;
int padre;
int primer_hijo;
int hermano_derecho;
int primer_bloque_data;
bool libre;

};
struct MetaData
{
    int tamano_bm;//bitmap size;
    int cantidad_entradas;
    int tamano_bloque;
    int cantidad_bloque;
};
struct Bm
{
    char *byte;
};

class VirtualDisk
{
private:

    const char *exito = "Se ha creado el disco!\n";
    int tamano_bytes = sizeof(byte);
    int tamano_entero = sizeof(entero_bytes);
    const char *cantidad_entradas_char = "Cantidad de entradas del disco : ";
    const char *cantidad_bloques_char = "Cantidad de bloques del disco : ";
    const char *tamano_bitmap = "Tamano del Bitmap del disco : ";
    const char *tamano_bloque_char = "Tamano del bloque del disco : ";
    long size;
    char *data;
    block_t bloque;
    MetaData metadata_t;
    FILE_ENTRY file_entry_t;

    char *bitmap;
    int bitmap_tamano;
    int byte_tamano = sizeof(byte);
    int tamano_bmp;
    int size_bmp;
    int tamano_disco;
    int posicion_directorio;
    char *directorio;
    char *return_bloque = new char[TAMANO_BLOQUES];
    int posicion_bloque = 0;
    char *archivo;
    int tamano_file_entrydirectorio;
    char *bloques = new char[1020];
    char usario[6] = "~root";
    int tamano_archivo;
public:
    ofstream salida;
    ifstream entrada;
    void Nuevo_disco(char *nombre,int cantidad_entradas,int cantidad_bloques);
    void Importar_archivo(char *nombre_archivo);
    void Exportar_archivo(char *nombre);
    void Asignar_file_entry_directorio();
    int Tamano_file_entry_directorio();
    void Asignar_file_entry_archivo(char *nombre_archivo, int cantidad_entradas);
    char *Directorio();
    char *Archivo();
    void Bitmap();
    char *Block();
    char *Tamano_Bitmap();
    int Primer_Bloque_vacio();
    void Mostar_MetaData();
    int getPosicionBloqueActual();
    int getPosicionDirectorioActual();
    void Siguinte_bloque(int x);
    char *DirectorioActual();
};

#endif // VIRTUALDISK_H
