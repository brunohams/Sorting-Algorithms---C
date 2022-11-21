#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void sort(int shiftIndex, int values[], int length) {

    // printf("shiftIndex %i\n", shiftIndex);

    if (shiftIndex >= length) {
        // Print array
        for (int i = 0; i < length; i++) {
            printf("Item %i\n", values[i]);
        }
        return;
    }
    
    int lowerValue = values[shiftIndex];
    int lowerIndex = shiftIndex;
    for (int i = shiftIndex; i < length; i++) {
        if (lowerValue > values[i]) {
            lowerValue = values[i];
            lowerIndex = i;
        }
    }
    // Swap values
    values[lowerIndex] = values[shiftIndex];
    values[shiftIndex] = lowerValue;
    // printf("lowerValue %i\n", lowerValue);
    
    sort(shiftIndex+1, values, length);

};



int main(void) {
    srand(time(NULL));   // Initialization, should only be called once.
    // int length = (int) sizeof(values) / sizeof(values[0]);
    // Ask int from prompt
    int length;
    printf("Give me an the length: \n");
    scanf("%i", &length);

    int values[length];

    for (int i = 0; i < length; i++) {
        int random = rand();
        values[i] = random;
    }
    
    // printf("Length %i\n", length);

    clock_t start, end;
    double cpu_time_used;
     
    start = clock();

    sort(0, values, length);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("cpu_time_used %f\n", cpu_time_used);
}