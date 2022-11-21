#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void sort(int values[], int length) {

    int executedTimes = 0;
    int allInOrder = 0;
    while (executedTimes < length && allInOrder == 0)
    {

        int needSwap = 0;

        for (int i = 0; i < length-1; i++) {
            
            if (values[i] > values[i+1]) {
                // Swap them
                int nextValue = values[i+1];
                values[i+1] = values[i];
                values[i] = nextValue;
                needSwap = 1;
            }

        }

        if (needSwap == 0){
            allInOrder = 1;
        }

        executedTimes = executedTimes + 1;
    }

    // Print array
    for (int i = 0; i < length; i++) {
        printf("Item %i\n", values[i]);
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

    for (int i = 0; i < length; i++) {
        int random = rand();
        values[i] = random;
    }
    
    // printf("Length %i\n", length);

    clock_t start, end;
    double cpu_time_used;
     
    start = clock();

    sort(values, length);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("cpu_time_used %f\n", cpu_time_used);
}