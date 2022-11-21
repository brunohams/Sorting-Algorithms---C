#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void sort(int values[], int length) {

    if (length == 1) {
        return;
    }

    int middleIndex = length / 2;
    printf("middleIndex %i\n", middleIndex);

    if (middleIndex == 1) {
        int rightValue = values[middleIndex];
        int leftValue = values[middleIndex-1];
        printf("rightValue %i\n", rightValue);
        printf("leftValue %i\n", leftValue);

        // Swap them
        if (leftValue > rightValue) {
            int nextValue = rightValue;
            values[middleIndex-1] = values[middleIndex];
            values[middleIndex] = values[middleIndex-1];
        }

    } else {

        int leftArrayLength = middleIndex+1;
        int leftArray[leftArrayLength];
        for (int i = 0; i < middleIndex; i++) {
            leftArray[i] = values[i];
        }

        if (leftArrayLength >= 2) {
            sort(leftArray, leftArrayLength);
        }

        int rightArrayLength = length-middleIndex+1;
        int rightArray[length-middleIndex];
        for (int i = middleIndex; i < length; i++) {
            rightArray[i] = values[i];
        }

        if (rightArrayLength >= 2) {
            sort(rightArray, rightArrayLength);
        }

    }

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
        values[i] = random / 1000000;
        printf("Item %i\n", values[i]);
    }
    printf("-----------------------------\n\n\n");
    
    // printf("Length %i\n", length);

    clock_t start, end;
    double cpu_time_used;
     
    start = clock();

    sort(values, length);

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