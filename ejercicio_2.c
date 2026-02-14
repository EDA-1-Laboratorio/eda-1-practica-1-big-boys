#include <stdio.h>

#define MAX 20

void generarEspiral(int n, int matriz[MAX][MAX]) {
    int valor = 1;
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {

        //  Izquierda a derecha
        for (int i = left; i <= right; i++) {
            matriz[top][i] = valor++;
        }
        top++;

        //  Arriba a abajo
        for (int i = top; i <= bottom; i++) {
            matriz[i][right] = valor++;
        }
        right--;

        //  Derecha a izquierda
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matriz[bottom][i] = valor++;
            }
            bottom--;
        }

        //  Abajo a arriba
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matriz[i][left] = valor++;
            }
            left++;
        }
    }
}

void imprimirMatriz(int n, int matriz[MAX][MAX]) {
    printf("\n--- Matriz Espiral de %dx%d ---\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    int matriz[MAX][MAX];

    printf("Ingrese el tamaño N de la matriz (1 - %d): ", MAX);

    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Error: Tamaño inválido.\n");
        return 1;
    }

    generarEspiral(n, matriz);
    imprimirMatriz(n, matriz);

    return 0;
}

// PREGUNTA: ¿Qué sucede si se omite la verificación if (top <= bottom) -linea 21- dentro del bucle?
// RESPUESTA: No ocurre nada porque antes tenemos un while que detiene la cuenta en n*n, esto significa que, al ser una matriz n*n,
// se detendrá la cuenta al llenarse los espacios; sin embargo, este if es para evitar que se recorra a una siguiente fila cuando
// los límites del espiral se cruzan.
