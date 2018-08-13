#include "virtualdisk.h"

void VirtualDisk::Nuevo_disco(char*nombre,int cantidad_entradas,int cantidad_bloques)
{
  strcat(nombre,".dat");
  salida.open(nombre,ios::out|ios::binary);
  if(!salida){cerr<<"No se puede abrir el arcihvo ";}
  this->bitmap_tamano = cantidad_bloques/this->byte_tamano;
  metadata_t.tamano_bm = this->bitmap_tamano;
  metadata_t.cantidad_entradas = cantidad_entradas;
  metadata_t.tamano_bloque = TAMANO_BLOQUES;
  metadata_t.cantidad_bloque = cantidad_bloques;
  salida.write(reinterpret_cast<char *> (&metadata_t),sizeof(metadata_t)) ;
  this->bitmap = new char[bitmap_tamano];


      for(int i=0;i<cantidad_bloques;i++)
      {
       this->bloque.siguiente = -1;
       salida.write(reinterpret_cast<char *>(&bloque),sizeof(bloque));
      }
      cout<<"Se creo el Disco correctamente"<<endl;
}
char *VirtualDisk::DirectorioActual()
{
    return this->usario;
}
int VirtualDisk::getPosicionBloqueActual()
{
    return this->posicion_bloque;
}
int VirtualDisk::Tamano_file_entry_directorio()
{
    this->tamano_file_entrydirectorio = sizeof(file_entry_t);
    return tamano_file_entrydirectorio;
}
void VirtualDisk::Asignar_file_entry_directorio()
{
    for(int i=0;i<this->bitmap_tamano;i++)
    {
        this->bitmap[i] = 0;
    }
    salida.write(bitmap,bitmap_tamano);

    for(int j=0;j<metadata_t.cantidad_bloque;j++)
    {
        if(j==0)
        {
            strcpy(file_entry_t.nombre,usario);
            file_entry_t.libre = false;
       }
        file_entry_t.tamano = 0;
        file_entry_t.tipo = 'D';
        file_entry_t.padre = SINPADRE;
        file_entry_t.primer_hijo = SINPADRE;
        file_entry_t.hermano_derecho = SINPADRE;
        file_entry_t.primer_bloque_data = SINPADRE;
        salida.write(reinterpret_cast<const char*>(&file_entry_t),sizeof(file_entry_t));
    }
    cout<<"Se ha podido asignar al file_entry"<<endl;
    return;
}
void VirtualDisk::Siguinte_bloque(int x)
{
    bloque.siguiente = x;
}
void VirtualDisk::Importar_archivo(char* nombre_archivo)
{
    this->entrada.open(nombre_archivo,ios::in|ios::binary);
    filebuf *pbuf;
    pbuf = entrada.rdbuf();

    this->size = pbuf->pubseekoff(0,ios::end,ios::in);
    pbuf->pubseekpos(0,ios::in);
    this->data = new char[size];
    pbuf->sgetn(data,size);
    this->entrada.close();
}
char *VirtualDisk::Block()
{
 strcpy(this->return_bloque,bloque.data);
 return return_bloque;
}
void VirtualDisk::Asignar_file_entry_archivo(char *nombre_archivo,int cantidad_entradas)
{
    strcpy(file_entry_t.nombre,nombre_archivo);
    file_entry_t.tamano = this->entrada.tellg();
    file_entry_t.tipo = 'A';
    file_entry_t.padre = getPosicionDirectorioActual();
    file_entry_t.primer_hijo = -1;
    file_entry_t.hermano_derecho = -1;
    file_entry_t.libre = false;
    salida.write(Archivo(),cantidad_entradas);
}
char *VirtualDisk::Directorio()
{
    this->directorio = new char[52];
    strcpy(directorio,file_entry_t.nombre);
    strcpy(directorio,(char*)&file_entry_t.hermano_derecho);
    strcpy(directorio,(char*)&file_entry_t.padre);
    strcpy(directorio,(char*)&file_entry_t.tamano);
    strcpy(directorio,(char*)&file_entry_t.primer_bloque_data);
    return directorio;
}
char *VirtualDisk::Archivo()
{
    this->archivo = new char[52];
    strcpy(archivo,file_entry_t.nombre);
    strcpy(archivo,(char*)&file_entry_t.hermano_derecho);
    strcpy(archivo,(char*)&file_entry_t.padre);
    strcpy(archivo,(char*)&file_entry_t.tamano);
    strcpy(archivo,(char*)&file_entry_t.primer_bloque_data);
    strcpy(archivo,(char*)file_entry_t.libre);
    return archivo;
}

void VirtualDisk::Exportar_archivo(char *nombre)
{
    this->salida.open(nombre,ios::out|ios::binary);
    this->salida.write(data,size);
    this->salida.close();
}
int VirtualDisk::getPosicionDirectorioActual()
{
    return this->posicion_directorio;
}
void VirtualDisk::Mostar_MetaData()
{
    char *byte_t;
    metadata_t.tamano_bloque = TAMANO_BLOQUES;
    this->tamano_bmp = sizeof(byte_t);
    metadata_t.tamano_bm = this->tamano_bmp;
    printf(tamano_bitmap);
    cout<<metadata_t.tamano_bm<<endl;
    printf(cantidad_entradas_char);
    cout<<metadata_t.cantidad_entradas<<endl;
    printf(tamano_bloque_char);
    cout<<metadata_t.tamano_bloque<<endl;
    printf(cantidad_bloques_char);
    cout<<metadata_t.cantidad_bloque<<endl;
    this->tamano_archivo = salida.tellp();
    cout<<"El tamano del disco es de : "<<this->tamano_archivo<<endl;
}
void VirtualDisk::Bitmap()
{
    char *bitmap_;
    bitmap_ = new char[this->bitmap_tamano];
    for(int i=0;i<this->bitmap_tamano;i++)
    {
        bitmap_[i] = 0;
    }
    this->entrada.read(bitmap,bitmap_tamano);
    for(int i=0;i<metadata_t.cantidad_entradas;i++)
    {
        if(i==0)
        {
            strcpy(file_entry_t.nombre,"~root$");
            file_entry_t.libre = false;
        }
        else
        {
            for(int j=0;j<30;j++)
            {
                file_entry_t.nombre[j] = '_';
            }
            file_entry_t.libre = true;
        }
        file_entry_t.tamano = 0;
        file_entry_t.tipo = '0';
        file_entry_t.padre = -1;
        file_entry_t.primer_hijo = -1;
        file_entry_t.hermano_derecho = -1;
        file_entry_t.primer_bloque_data = -1;
        this->salida.write(reinterpret_cast< char*>(&file_entry_t),sizeof(file_entry_t));
    }
    for(int i=0;i<metadata_t.cantidad_bloque;i++)
    {
        block_t data;
        this->salida.write(reinterpret_cast<char*>(&data),sizeof(data));
    }
    return;
}

int VirtualDisk::Primer_Bloque_vacio()
{
//	int tama = (sizeof(bitmap_tamano)*8;
  /* for(int i=0;i<tama;i++)
    {
        if(i==0)
        {
            return i;
        }
    }
    return -1;*/
}
