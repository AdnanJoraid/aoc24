#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000
#define FILENAME "day1_input.txt"

int setup(int* left, int* right) {
    FILE* file; 
    file = fopen(FILENAME, "r");
    if (file == NULL) return -1;
    int templeft, tempright;
    int i = 0, j = 0;
    while (fscanf(file, "%d %d", &templeft, &tempright) == 2) {
        left[i++] = templeft;
        right[j++] = tempright;
    }
    fclose(file);
    return 1;
}

int comp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    int left[1000], right[1000];
    if (setup(left, right) == -1) {
        printf("Error opening the file in setup\n");
        return 0;
    }
    qsort(left, MAX_SIZE, sizeof(int), comp);
    qsort(right, MAX_SIZE, sizeof(int), comp);
    int res = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        res += abs(left[i] - right[i]);
    }

    printf("%d\n", res);
}