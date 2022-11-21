#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 50;
    int *pointer = &n;

    printf("%p\n", pointer);
    printf("%i\n", *pointer);
}