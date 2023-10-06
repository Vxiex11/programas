#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int busqueda_lineal(int *A, int n, int valor2);

int main() {

    int n = 0, valor1;

    //abrir el archivo con numeros desordenados para lectura
    FILE *archivo = fopen("numeros10millones.txt", "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo de números desordenados");
        return 1;
    }

    int numero;
    while (fscanf(archivo, "%d", &numero) == 1) {
        n++;
    }

    //regresar al inicio del archivo
    fseek(archivo, 0, SEEK_SET);

    int A[n];  //declarar un arreglo de tamaño n

    
    printf("Ingrese el valor de n: ");
    scanf("%d", &n);

    //validar que la cantidad de numeros a ordenar sea valida
    if (n < 1 || n > 10000000) {
        printf("Cantidad no valida.\n");
        fclose(archivo);
        exit(1);
    }

   int *A = (int *)malloc(n * sizeof(int)); // Apartar memoria para n números enteros
    if (A == NULL) {
        printf("\nError al intentar reservar memoria para %d elementos\n", n);
        fclose(archivo);
        exit(1);
    }

      //leer los numeros desde el archivo y almacenarlos en el arreglo
    for (int i = 0; i < n; i++) {
        if (fscanf(archivo, "%d", &A[i]) != 1) {
            perror("Error al leer los números desde el archivo");
            fclose(archivo);
            return 1;
        }
    }

    fclose(archivo);

    printf("Ingrese el valor a buscar: "); //leer el valor a buscar
    scanf("%d", &valor1);

    //iniciar la medicion de tiempo
    clock_t t_inicio = clock();

    int comparaciones = busqueda_lineal(A, n, valor1); //realizar la busqueda lineal

    //finalizar medicion de tiempo
    clock_t t_final = clock();
    double t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;

    if (comparaciones != -1) { // Si se encuentra el valor
        printf("El valor %d fue encontrado después de %d comparaciones.\n", valor1, comparaciones);
        //guardar el valor encontrado en un archivo
        FILE *archivo = fopen("resultado.txt", "w");
        if (archivo != NULL) {
            fprintf(archivo, "El valor %d fue encontrado después de %d comparaciones.\n", valor1, comparaciones);
            fclose(archivo);
        } else {
            perror("Error al abrir el archivo para escribir el resultado.");
        }
    } else {
        printf("El valor %d no fue encontrado en el arreglo.\n", valor1);
    }

    printf("Tiempo de ejecucion: %.6f segundos\n", t_intervalo);

    return 0;
}

int busqueda_lineal(int *A, int n, int valor2){
   int res=-1;
    for(int i=0; i=n-1; i++){
        if (A[i] == valor2){
            res = i;
        }
    }
    return res;
}