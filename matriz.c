#include <stdio.h>

void imprima(int matriz[255][255], int tamanho){
    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void diagonal(int matriz[255][255], int tamanho, int num){
    int diag = 1;
    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            if (i != j && matriz[i][j] != 0){
                diag = 0;
                break;
            }
        }
        if (diag == 0)
            break;
    }

    if(diag){
        printf("A matriz %d eh diagonal\n", num);
    }
    else{
        printf("A matriz %d nao eh diagonal\n", num);
    }
}

void multiplicada(int matrizA[255][255], int a, int matrizB[255][255], int b){

    int resultado[255][255] = {0};

    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            resultado[i][j] = 0;
            for (int k = 0; k < a; k++){
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    imprima(resultado, a);
}

int main (void){
    int n, m;
    scanf("%d %d", &n, &m);
    int matrizA[255][255], matrizB[255][255];

    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &matrizA[i][j]);
        }
    }

    for(int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &matrizB[i][j]);
        }
    }
	
    printf("Matrizes:\n");
    imprima(matrizA, n);

    imprima(matrizB, m);

    diagonal(matrizA, n, 1);

    diagonal(matrizB, m, 2);

    if(n == m){	    
       printf("Matriz multiplicada:\n");
       multiplicada(matrizA, n, matrizB, m);
    }
    else{
	printf("Matrizes de tamanho incompativel");
    }

    return 0;
}

