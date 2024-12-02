#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
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

int main(void) {
    int left[1000], right[1000];
    std::map<int, int> freq;
    if (setup(left, right) == -1) {
        printf("Error opening the file in setup\n");
        return 0;
    }
    for (int i = 0; i < MAX_SIZE; i++) {
        freq[right[i]] += 1;
    }

    int res = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (freq.find(left[i]) != freq.end()) res += (left[i] * freq[left[i]]);
    }
    printf("%d\n", res);
    return 1;
}