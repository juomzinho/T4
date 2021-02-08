#include <stdio.h>
#include <stdlib.h>

typedef void* No;
typedef void* Info;
typedef void* Arvore;
typedef void* Pai;
typedef void* Filho;

typedef struct NoStruct{
    struct NoStruct *Nw, *Ne, *Sw, *Se;
    Info info;
}Node;


