struct Malos{
    char first_name[100];
    int danger_category;
    float attack_prob;
};
typedef struct Malos malos;

malos* getArray(char *archivo_csv);
NumFilas(char*archivo_csv);
void swap(malos *arreglo, int n);
