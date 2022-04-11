#include "header.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX_LINE_SIZE 1000
int NumFilas(char*archivo_csv){
    int cont = 0;
    FILE *fp = fopen(archivo_csv, "r");
    char line[MAX_LINE_SIZE];
    while(!feof(fp)) {
        fgets(line, 2000, fp);
        cont++;
    }
    return cont;
}

// A function to implement bubble sort

void swap(malos *arreglo, int n){
    int i,j,aux;
    for(i=0;i<n-1;i++) //Ciclo que se repetirá 5 veces para ordenar cada nombre
        for(j=0;j<n-i;j++) //Ciclo que ordenara un nombre, se va restando pues en cada vuelta queda ordenado el ultimo nombre
            if(arreglo[j].danger_category>arreglo[j+1].danger_category) //Si el nombre actual es mayor al siguiente nombre...
            {
                strcpy(aux,arreglo[j]); //Guardamos el nombre actual en Aux
                strcpy(arreglo[j],arreglo[j+1]); //Pasamos el nombre siguiente al actual
                strcpy(arreglo[j+1],aux); //Pasamos el Aux al siguiente
            }
    //debug
    int k;
    for (k=0; k < n; k++)
        printf("%s ", arreglo[k].first_name);
    printf("\n");
}

/* Function to print an array */
