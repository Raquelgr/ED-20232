#include <metodosConhecidos.hpp>

void BubbleSort(int *item, int tamanho) {
    bool trocou;
    int aux = 0;

    for (int i = 0; i < tamanho - 1; i++) {
        trocou = false;

        for (int j = 1; j < tamanho - i; j++) {
            if (item[j] < item[j - 1]) {
                aux = item[j - 1];
                item[j] = item[j - 1];      
                item[j - 1] = aux; 

                trocou = true;
            }
        }

        if (!trocou) break;
    }
}

void SelectionSort(int *item, int tamanho) { 
    int min;
    int aux = 0;

    for (int i = 0; i < tamanho - 1; i++) {
        min = i;

        for (int j = i + 1; j < tamanho; j++) {
            if (item[j] < item[min]) {
                min = j;
            }
        }

        if (min != i) {
            aux = item[min];
            item[min] = item[i];      
            item[i] = aux; 
        }
    }

}

void InserctionSort(int *item, int tamanho) {
    int j = 0;
    int aux;

    for (int i = 1; i < tamanho; i++) {
        aux = item[i];
        j = i - 1;

        while (j >= 0 && aux < item[j]) {
            item[j + 1] = item[j];
            j--;
        }
        item[j + 1] = aux;
    } 
}