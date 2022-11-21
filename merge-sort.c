#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void merge(int values[], int left, int mid, int right) {

    // Create array from the left side
    int leftArrayLength = mid - left + 1;
    int leftArray[leftArrayLength];

    // Create array from the right side
    int rightArrayLength = right - mid;
    int rightArray[rightArrayLength];

    // Populate Left
    for (int i = 0; i < leftArrayLength; i++) {
        leftArray[i] = values[left + i];
    }

    // Populate Right
    for (int i = 0; i < rightArrayLength; i++) {
        rightArray[i] = values[mid + 1 + i];
    }

    int leftTempIndex = 0;
    int rightTempIndex = 0;
    int mainArrayIndex = left;

    while (leftTempIndex < leftArrayLength && rightTempIndex < rightArrayLength) {
        
        // Replace in the main array values, if left is smaller / or vice-versa
        if (leftArray[leftTempIndex] <= rightArray[rightTempIndex]) {
            values[mainArrayIndex] = leftArray[leftTempIndex];
            leftTempIndex++;
        } else {
            values[mainArrayIndex] = rightArray[rightTempIndex];
            rightTempIndex++;
        }

        mainArrayIndex++;
    }

    // If IMPAR, adiciona os faltantes
    // Se acabou o right primeiro e tem left faltando para incluir
    while (leftTempIndex < leftArrayLength) {
        values[mainArrayIndex] = leftArray[leftTempIndex];
        mainArrayIndex++;
        leftTempIndex++;
    }
    
    // If IMPAR, adiciona os faltantes
    // Se acabou o left primeiro e tem right faltando para incluir
    while (rightTempIndex < rightArrayLength) {
        values[mainArrayIndex] = rightArray[rightTempIndex];
        mainArrayIndex++;
        rightTempIndex++;
    }

}

void sort(int values[], int left, int right) {

    if (left >= right) {
         return; 
    }

    int mid = left + (right - left) / 2;

    sort(values, left, mid);
    sort(values, mid+1, right);
    merge(values, left, mid, right);

};

int main(void) {
    srand(time(NULL));   // Initialization, should only be called once.
    // int length = (int) sizeof(values) / sizeof(values[0]);
    // Ask int from prompt
    int length;
    printf("Give me an the length: \n");
    scanf("%i", &length);

    int values[length];

    printf("\n\n\n----------- GIVEN -----------\n");
    for (int i = 0; i < length; i++) {
        int random = rand();
        values[i] = random;
        printf("Item %i\n", values[i]);
    }
    printf("-----------------------------\n\n\n");
    
    clock_t start, end;
    double cpu_time_used;
     
    start = clock();

    sort(values, 0, length-1);

    // Print array
    printf("\n\n\n----------- RESULT -----------\n");
    for (int i = 0; i < length; i++) {
        printf("Item %i\n", values[i]);
    }
    printf("-----------------------------\n\n\n");

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("cpu_time_used %f\n", cpu_time_used);
}