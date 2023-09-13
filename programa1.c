#include <stdio.h>

int main() {
    int m = 1;
    
    while (1) {
        int suma_n = 0;

        // Calculamos la suma de valores de n desde 1 hasta m - 1
        for (int n = 1; n < m; n++) {
            suma_n += n;
        }

        // Comparamos m con la suma de valores de n
        if (m == suma_n) {
            printf("El valor de m que cumple la condición es: %d\n", m);
            break; // Salimos del bucle una vez que encontramos la solucion
        }

        m++; // Incrementamos m para probar el siguiente valor
    }

    return 0;
}
