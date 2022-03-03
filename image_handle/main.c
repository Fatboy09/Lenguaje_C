#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "imagen.h"

unsigned char* RGBtoGray(unsigned char* imgRGB, uint32_t width, uint32_t height);
unsigned char* reservarMemoria(uint32_t width, uint32_t height);



int main() {

    bmpInfoHeader infoH;    
    unsigned char* imgRGB;
    unsigned char* imgGray;

    imgRGB = abrirBMP("hoja.bmp",&infoH);
    displayInfoBMP(&infoH);
    
    imgGray = RGBtoGray(imgRGB,infoH.width,infoH.height);
    guardarBMP("output/hojaGray.bmp",&infoH,imgGray);

    free(imgRGB);
    free(imgGray);
    
    return 0;
}

unsigned char* reservarMemoria(uint32_t width, uint32_t height) {

    unsigned char* arr = (unsigned char*) malloc(sizeof(unsigned char) * width * height * 3);
    return arr;
}

unsigned char* RGBtoGray(unsigned char* imgRGB, uint32_t width, uint32_t height) {
    
    int idxGray, idxRGB;
    unsigned char nivelGris;
    unsigned char* imgGray = reservarMemoria(width,height);

    if(!imgGray) {
        fprintf(stderr,"Error al reservar espacion en memoria\n");
        exit(EXIT_FAILURE);
    }

    for(register int y = 0; y < (int)height; y++) {
        for(register int x = 0; x < (int)width; x++) {
            idxGray = (y * (int)width + x);
            idxRGB = idxGray * 3;
            nivelGris = (unsigned char) ((imgRGB[idxRGB]*0.11) + (imgRGB[idxRGB+1]*0.59) + (imgRGB[idxRGB+2]*0.3));
            imgGray[idxGray * 3] = nivelGris;
            imgGray[(idxGray * 3) + 1] = nivelGris;
            imgGray[(idxGray * 3) + 2] = nivelGris;
            //printf("%d ",idxGray);
        }
        //printf("\n");
    }

    return imgGray;
}