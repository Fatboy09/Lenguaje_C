#ifndef IMAGE_H
#define IMAGE_H

#include <stdint.h>

typedef struct bmpFileHeader {
    /*2 bytes de indentificacion*/
    uint32_t size;          //tamaño del archivo
    uint16_t resv1;         //reservado
    uint16_t resv2;         //reservado
    uint32_t offset;        //offset hasta los datos de la imagen
} bmpFileHeader;

typedef struct bmpInfoHeader {
    uint32_t size_header;   //tamanio del header
    uint32_t width;         //width de la imagen
    uint32_t height;        //height de la imagen
    uint16_t planes;         //planos de color (debe ser 1)
    uint16_t bpp;           //bits por pixel
    uint32_t compress;      //compresion
    uint32_t size_image;    //tamanio de la imagen
    uint32_t bpmx;          //resolucion en x por metro
    uint32_t bpmy;          //resolucion en y por metro
    uint32_t colors;         //colores usados en la paleta
    uint32_t imxtcolors;    //colores importantes. 0 si son todos
} bmpInfoHeader;

unsigned char* abrirBMP(const char* fileName, bmpInfoHeader* infoHeader);
void guardarBMP(const char* fileName, bmpInfoHeader* infoHeader, unsigned char* imgdata);
void displayInfoBMP(bmpInfoHeader* infoHeader);

#endif //IMAGE_H