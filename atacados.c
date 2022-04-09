#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>


typedef struct{
char *first_name;
  int danger_category;
  float attack_prob;
}Malos;

Malos * ma; 

void sacar(char temp[]);
void copiar(char temp[], int i);

void sacar(char temp[]) {
  int i;
  for(i=0; i<2000;i++) {
    temp[i]= '\0'; //Eliminamos la información vacia 
  }
}

void copiar(char temp[], int i){
  int N= strlen(temp)+1; //contamos las letras del string
  ma[i].first_name=(char*)malloc(N*sizeof(char));

  strcpy(ma[i].first_name, temp);
  
  
}


void SortDanger(Malos e[], int n) {
  int i,j;
  Malos temp;
  for(i=0; i<n-1; i++){
    for(j=0;j<n;j++){
      if(e[i].danger_category>e[j].danger_category){
        temp=e[i];
        e[i]=e[j];
        e[j]=temp;
      }
    }
    
  }
  
}




int main() {
  int i, j;
  char ne;
  char temp[2000];
  int cont = 0;
  FILE *fp;
fp=fopen("lista.txt", "r");

  while(!feof(fp)) {
    fgets(temp, 2000, fp);
    cont++;
  }

  rewind(fp);
  ma = (Malos*)malloc(cont*sizeof(Malos));

  for(i=0; !feof(fp); i++) {
    sacar(temp);
    ne='0';
    for(j=0; ne!= ','; j++) {
      ne=fgetc(fp);
      if(ne!=','){
        temp[j]=ne;
      }
    }
    copiar(temp,i);

    fgets(temp,2000,fp);
    ma[i].danger_category=atoi(temp);
    //ma[i].attack_prob=atof(temp);
 //   printf("Nombre: %s\n", ma[i].first_name);
    //printf("Danger_Category:  %d\n", ma[i].danger_category);
   // printf("Attack_Prob:  %f\n", ma[i].attack_prob);

   // SortDanger(ma, cont);
   // printf("%d: \n", ma[i].danger_category);
    
  }



  return 0;

}
