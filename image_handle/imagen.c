#include <stdio.h>
#include <stdlib.h>
#include "imagen.h"

unsigned char* abrirBMP(const char* fileName,bmpInfoHeader* infoHeader) {
    
    FILE* stream = fopen(fileName,"rb");
    bmpFileHeader header;
    unsigned char* imgdata = NULL;
    uint16_t type;

    if(stream == NULL) {
        fprintf(stderr,"Error al abrir la imagen\n");
        exit(EXIT_FAILURE);
    }
    //leemos los dos primeros bytes
    fread(&type,sizeof(uint16_t),1,stream);
    
    if(type != 0x4D42) {
        printf("Error en el formato de la imagen, debe ser BMP de 24 bits\n");
        fclose(stream);
        return NULL;
    }

    //leemos la cabecera del fichero completa
    fread(&header,sizeof(bmpFileHeader),1,stream);

    //leemos la cabecera de informacion completa
    fread(infoHeader,sizeof(bmpInfoHeader),1,stream);

    //reservamos espacio en memoria para la imagen ¿cuanta? la que indique imgsize
    imgdata = (unsigned char*) malloc(infoHeader->size_image);
    
    if(imgdata == NULL) {
        fprintf(stderr,"Error al reservar espacio en memoria\n");
        fclose(stream);
        exit(EXIT_FAILURE);
    }

    //nos situamos en la posicion donde comienza la info de la imagen
    fseek(stream,header.offset,SEEK_SET);

    //leemos los datos de la imagen, tantos bytes como imgsize
    fread(imgdata,infoHeader->size_image,1,stream);

    fclose(stream);
    return imgdata;
}

void guardarBMP(const char* fileName, bmpInfoHeader* infoHeader, unsigned char* imgdata) {
    
    FILE* stream = fopen(fileName,"wb+");
    uint16_t type;
    bmpFileHeader header;

    if(stream == NULL) {
        fprintf(stderr,"Error al abrir el archivo en modo escritura\n");
        exit(EXIT_FAILURE);
    }

    header.size = infoHeader->size_image + sizeof(bmpInfoHeader) + sizeof(bmpFileHeader);
    /* header.resv1=0; */
  	/* header.resv2=1; */
  	/* El offset será el tamaño de las dos cabeceras + 2 (información de fichero)*/
    header.offset = sizeof(bmpFileHeader) + sizeof(bmpInfoHeader) + 2;
    //Escribimos la identificacion del archivo
    type = 0x4D42;
    fwrite(&type,sizeof(type),1,stream);
    //Escribimos la cabecera del archivo
    fwrite(&header,sizeof(bmpFileHeader),1,stream);
    //Escribimos la informacion basica del archivo
    fwrite(infoHeader,sizeof(bmpInfoHeader),1,stream);
    //escribimos la imagen
    fwrite(imgdata,infoHeader->size_image,1,stream);

    fclose(stream);
}

void displayInfoBMP(bmpInfoHeader* infoHeader) {
    
    printf("Tamaño de la cabecera: %u\n", infoHeader->size_header);
  	printf("Anchura: %d\n", infoHeader->width);
  	printf("Altura: %d\n", infoHeader->height);
  	printf("Planos (1): %d\n", infoHeader->planes);
  	printf("Bits por pixel: %d\n", infoHeader->bpp);
  	printf("Compresión: %d\n", infoHeader->compress);
  	printf("Tamaño de datos de imagen: %u\n", infoHeader->size_image);
  	printf("Resolucón horizontal: %u\n", infoHeader->bpmx);
  	printf("Resolucón vertical: %u\n", infoHeader->bpmy);
  	printf("Colores en paleta: %d\n", infoHeader->colors);
  	printf("Colores importantes: %d\n", infoHeader->imxtcolors);
}