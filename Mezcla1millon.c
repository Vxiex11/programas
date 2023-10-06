#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void Mergesort(int *A, int p, int r);

int main(int ARc, char *ARv[]) {

    // Variables para la medicion de tiempos
    clock_t t_inicio, t_final;
    double t_intervalo;

    // Variables para el algoritmo
    int n = 0, *A, numero;
    int numeros_a_ordenar;

    // Recibir por argumento el nombre del archivo
    if (ARc != 2) {
        printf("\numeros1M.txt\n", ARv[0]);
        exit(1);
    }

    // Abrir el archivo
    FILE *archivo = fopen(ARv[1], "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        exit(1);
    }

    // Leer los numeros desde el archivo y contar cuántos hay
    while (fscanf(archivo, "%d", &numero) == 1) {
        n++;
    }

    // Regresar al inicio del archivo
    fseek(archivo, 0, SEEK_SET);

    // Recibir por entrada estandar la cantidad de numeros a ordenar
    printf("Ingrese cuantos numeros desea ordenar (menos o igual a 1,000,000): ", n);
    scanf("%d", &numeros_a_ordenar);

    // Validar que la cantidad de numeros a ordenar sea valida
    if (numeros_a_ordenar < 1 || n > 1000000) {
        printf("Cantidad no valida. Debe ser un numero entre 1 y 1,000,000.\n");
        fclose(archivo);
        exit(1);
    }

    // Apartar memoria para n numeros enteros
    A = (int *)malloc(numeros_a_ordenar * sizeof(int));
    if (A == NULL) {
        printf("\nError al intentar reservar memoria para %d elementos\n", numeros_a_ordenar);
        fclose(archivo);
        exit(1);
    }

    // Leer los numeros desde el archivo y almacenarlos en el arreglo
    for (int i = 0; i < numeros_a_ordenar; i++) {
        if (fscanf(archivo, "%d", &A[i]) != 1) {
            perror("Error al leer los numeros desde el archivo");
            free(A);
            fclose(archivo);
            exit(1);
        }
    }

    fclose(archivo);

    // Inicia medicion del tiempo
    t_inicio = clock();

    // Llamar al algoritmo de mezcla
    Mergesort(A, 0, numeros_a_ordenar - 1);

    // Termina medicion del tiempo
    t_final = clock();

    // Enviar a la salida estandar el arreglo ordenado
    printf("\nArreglo ordenado:\n");
    for (int i = 0; i < numeros_a_ordenar; i++)
        printf("%d ", A[i]);
    printf("\n");

      // Calculo del tiempo y enviar mensaje a salida estandar con la medicion
    t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;
    printf("\nTiempo medido: %.10f segundos.", t_intervalo);

    // Liberar memoria
    free(A);

    return 0; //retornaer a 0
}

void Merge (int *A, int p, int q, int r){
	int l=r - p + 1;
	int i=p;
	int j=q + 1;
	int k, C[l];
	
	for (k = 0; k < l; k++){
		if(i<=q && j <= r){
			if (A[i] < A[j]){
				C[k] = A[i];
				i++;
			}
			else {
				C[k] = A[j];
				j++;
			}
		}
		else if(i <= q){
			C[k] = A[i];
			i++;
		}
		else {
			C[k] = A[j];
			j++;
		}	
	}
	k = p;
	for (i = 0; i < l;i ++ ){
		A[k] = C[i];
		k++; 
	}

}

void Mergesort(int *A, int p, int r){
	if (p<r){
		int q = (p + r)/2;
		Mergesort (A, p, q);
		Mergesort (A, q+1, r);
		Merge (A, p, q, r);
	}
}

