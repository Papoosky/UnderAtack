#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include<stdlib.h>
#include "header.h"


#define MAX_LINES 1000
#define MAX_LINE_SIZE 1000

int main(int argc, char *argv[])
{
    int cont;
    malos *arreglo;
    char* archivo_csv;
    archivo_csv = argv[1];
    arreglo = getArray(archivo_csv);

    //cont = NumFilas(archivo_csv);
    //swap(arreglo, cont);
    return 0;

}
