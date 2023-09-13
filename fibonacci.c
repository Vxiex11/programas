#include <stdio.h>
#include <stdlib.h> // Necesario para la función atoi

//Resendiz Rios Diego Emiliano

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    char input[50];
    int n;

    printf("Ingrese el numero de terminos de la serie de Fibonacci que desea generar: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        if (sscanf(input, "%d", &n) == 1) {
            printf("Serie de Fibonacci:\n");
            for (int i = 0; i < n; i++) {
                printf("%d ", fibonacci(i));
            }
            printf("\n");
        } else {
            printf("Entrada no valida. Debe ingresar un numero.\n");
        }
    } else {
        printf("Error al leer la entrada.\n");
    }

    return 0;
}
