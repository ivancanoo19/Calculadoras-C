#include <iostream>

// Función que imprime una matriz. Nótese su manejo como matriz "normal".
// Recibe un apuntador de apuntadores representando la matriz y no regresa nada.
void imprimir_matriz(float **matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cout << matriz[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

// Función que llena con valores una matriz. Nótese su manejo como matriz "normal".
// Recibe un apuntador de apuntadores representando la matriz y no regresa nada.
void llenar_matriz(float **matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cout << "Ingresa el elemento (" << i + 1 << ", " << j + 1 << "): ";
            std::cin >> matriz[i][j];
        }
    }
}

void sumar(float **matriz1, float **matriz2, float **resultado, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

void resta(float **matriz1, float **matriz2, float **resultado, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultado[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }
}

void mult(float **matriz1, float **matriz2, float **resultado, int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultado[i][j] = 0;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for(int k=0; k<n; k++){
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}



int main(void) {
    int filas, columnas;

    std::cout << "Ingresa el número de filas y columnas: ";
    std::cin >> filas;
    columnas = filas;

    float **matriz1, **matriz2, **resultado;

    // Reservar memoria para la primera matriz
    matriz1 = new float *[filas];
    for (int i = 0; i < filas; i++) {
        matriz1[i] = new float[columnas];
    }

    // Reservar memoria para la segunda matriz
    matriz2 = new float *[filas];
    for (int i = 0; i < filas; i++) {
        matriz2[i] = new float[columnas];
    }

    // Reservar memoria para la matriz resultado
    resultado = new float *[filas];
    for (int i = 0; i < filas; i++) {
        resultado[i] = new float[columnas];
    }

    // Llenar las dos matrices
    std::cout << "Llena la primera matriz:\n";
    llenar_matriz(matriz1, filas, columnas);

    std::cout << "Llena la segunda matriz:\n";
    llenar_matriz(matriz2, filas, columnas);
    

    std::cout << "\nMatriz 1:\n";
    imprimir_matriz(matriz1, filas, columnas);

    std::cout << "\nMatriz 2:\n";
    imprimir_matriz(matriz2, filas, columnas);

    //Sumar
    sumar(matriz1, matriz2, resultado, filas);
    std::cout << "\nResultado de la suma:\n";
    imprimir_matriz(resultado, filas, columnas);

    //Restar
    resta(matriz1, matriz2, resultado, filas);
    std::cout << "\nResultado de la suma:\n";
    imprimir_matriz(resultado, filas, columnas);

    //Multiplicar
    mult(matriz1, matriz2, resultado, filas);
    std::cout << "\nResultado de la multiplicacion:\n";
    imprimir_matriz(resultado, filas, columnas);

    // Liberar memoria
    for (int i = 0; i < filas; i++) {
        delete[] matriz1[i];
        delete[] matriz2[i];
        delete[] resultado[i];
    }
    delete[] matriz1;
    delete[] matriz2;
    delete[] resultado;

    return 0;
}
