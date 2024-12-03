#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1000
#define MAXLINE 15
#define FILENAME "day2_input.txt"

int setup(int*** reports, int* sizes) {
    FILE* file = fopen(FILENAME, "r");
    if (file == NULL) return -1;
    *reports = malloc(sizeof(int*) * MAXSIZE);
    if (*reports == NULL) {
        fclose(file);
        return -1;
    }
    char buffer[128];
    int count = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        int* sub = malloc(sizeof(int) * MAXLINE);
        int item = 0;
        char* token = strtok(buffer, " \n");
        while (token != NULL) {
            sub[item++] = atoi(token);
            token = strtok(NULL, " \n");
        }
        (*reports)[count] = sub;
        sizes[count] = item;
        count++;
    }
    fclose(file);
    return 1;
}

int is_safe(int a, int b, int decreasing) {
    if (decreasing && (b > a || a - b <= 0 || a - b > 3)) return 0;
    if (!decreasing && (a > b || b - a <= 0 || b - a > 3)) return 0;
    return 1;
}

int main(void) {
    int** reports;
    int sizes[MAXSIZE];
    int safe_reports_count = 0;
    if (setup(&reports, sizes) == -1) {
        printf("error in setup.\n");
    }
    for (int i = 0; i < MAXSIZE; i++) {
        int safe = 1;
        int is_decreasing = reports[i][0] > reports[i][1];
        for (int j = 0; j < sizes[i] - 1; j++) {
            if (!is_safe(reports[i][j], reports[i][j+1], is_decreasing)) {
                safe = 0;
                break;
            }
        }
        safe_reports_count += safe ? 1 : 0;
    }
    for (int i = 0; i < MAXSIZE; i++) {
        free(reports[i]);
    }
    free(reports);
    printf("%d\n", safe_reports_count);
    return 1;
}