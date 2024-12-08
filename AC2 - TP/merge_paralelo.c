//Merge Sort Paralelizado

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>  // Biblioteca OpenMP

//Declaração das Funções
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void printArray(int arr[], int size);

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 325, 190, 88, 2, 5, 290, 54, 38, 21, 1, 999, 4, 98, 91, 63, 33, 21, 998, 991, 723, 745, 98, 75, 30, 10, 8, 74, 65}; // Array de exemplo
    int n = sizeof(arr) / sizeof(arr[0]);  // Tamanho do array

    printf("Array original: \n");
    printArray(arr, n);

    // Definir número de threads
    omp_set_num_threads(4);  // Por exemplo, 4 threads

    // Medir tempo de execução
    mergeSort(arr, 0, n - 1);  // Chama a função Merge Sort
    
    printf("Array ordenado: \n");
    printArray(arr, n);

    return 0;
}


//Merge
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

//MergeSort - paralelizado
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Paralelizar as chamadas recursivas para as duas metades
        #pragma omp parallel sections
        {
            #pragma omp section
            mergeSort(arr, l, m);

            #pragma omp section
            mergeSort(arr, m + 1, r);
        }

        merge(arr, l, m, r);  // Mescla as duas metades ordenadas
    }
}

//Imprimir
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}