// kernel.c

#include "queue.h"

void clearScr(char *vidptr) {
    unsigned int i = 0;
    unsigned int j = 0;

    //clear all
    while(j < 80 * 25 * 2) {
        //blank character
        vidptr[j] = ' ';
        //attribute-byte: light grey on black screen
        vidptr[j+1] = 0x07;
        j = j + 2;
    }
    return;
}

void prog1Run(char *vidptr) {
    clearScr(vidptr);

    char *str = "prog 1 running";
    unsigned int i = 0;
    unsigned int j = 0;

    while(str[j] != '\0') {
        vidptr[i] = str[j];
        vidptr[i+1] = 0x04;  // attribute-byte
        ++j;
        i = i + 2;
    }

    return;
}

void sleep(unsigned int mseconds) {
    for(long i=0; i < mseconds * 100000; i++); // this is stupid
}


void kmain(void) {
    char *str = "booted.";
    char *vidptr = (char*)0xb8000;  // video memory begins here

    clearScr(vidptr);

    unsigned int i = 0;
    unsigned int j = 0;
    while(str[j] != '\0') {
        vidptr[i] = str[j];
        vidptr[i+1] = 0x03;
        ++j;
        i = i + 2;
    }
    sleep(1000);

    prog1Run(vidptr);

    return;
}

