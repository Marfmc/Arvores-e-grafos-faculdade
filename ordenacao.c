#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// --- Funções Auxiliares ---

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void copyArray(int source[], int dest[], int size) {
    for (int i = 0; i < size; i++) dest[i] = source[i];
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// --- 1. Bubble Sort ---
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

// --- 2. Selection Sort ---
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx]) min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

// --- 3. Insertion Sort ---
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// --- 4. Quick Sort ---
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// --- 5. Merge Sort ---
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
    }
}

// --- 6. Shell Sort ---
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

// --- Main e Menu ---
int main() {
    int n;
    printf("Digite o tamanho do array para o teste: ");
    scanf("%d", &n);

    int *original = malloc(n * sizeof(int));
    int *work = malloc(n * sizeof(int));

    // Gerar array aleatorio
    srand(time(NULL));
    for (int i = 0; i < n; i++) original[i] = rand() % 1000;

    int opcao;
    clock_t start, end;
    double cpu_time_used;

    do {
        printf("\n--- MENU DE ORDENACAO ---\n");
        printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n");
        printf("4. Quick Sort\n5. Merge Sort\n6. Shell Sort\n0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 6) {
            copyArray(original, work, n);
            printf("\nArray original (primeiros 10): ");
            printArray(work, n > 10 ? 10 : n);

            start = clock();
            switch(opcao) {
                case 1: bubbleSort(work, n); break;
                case 2: selectionSort(work, n); break;
                case 3: insertionSort(work, n); break;
                case 4: quickSort(work, 0, n - 1); break;
                case 5: mergeSort(work, 0, n - 1); break;
                case 6: shellSort(work, n); break;
            }
            end = clock();

            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Array ordenado (primeiros 10): ");
            printArray(work, n > 10 ? 10 : n);
            printf("Tempo de execucao: %f segundos\n", cpu_time_used);
        }
    } while (opcao != 0);

    free(original);
    free(work);
    return 0;
}