#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_SIZE 100
#define MAX_SIZE 2000
#define STEP_SIZE 100

double **allocate_matrix(int size) {
    double **matrix = (double **)malloc(size * sizeof(double *));
    if (matrix == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; i++) {
        matrix[i] = (double *)malloc(size * sizeof(double));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
    return matrix;
}

void free_matrix(double **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    FILE *file = fopen("output3.txt", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return EXIT_FAILURE;
    }

    clock_t start_time, end_time;
    double elapsed_time;

    for (int size = MIN_SIZE; size <= MAX_SIZE; size += STEP_SIZE) {
        // Allocate memory for matrices A, B, and C
        double **A = allocate_matrix(size);
        double **B = allocate_matrix(size);
        double **C = allocate_matrix(size);

        // Initialize matrices A and B
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                A[i][j] = 1.0;
                B[i][j] = 2.0;
            }
        }

        // Perform matrix multiplication
        start_time = clock();

        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                double r = B[k][j]; // Fetch the element B[k][j] once for reuse
                for (int i = 0; i < size; i++) {
                    C[i][j] += A[i][k] * r;
                }
            }
        }

        end_time = clock();

        elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        fprintf(file, "%d %f\n", size, elapsed_time);
        printf("Matrix multiplication for size %d took %f seconds\n", size, elapsed_time);

        // Free allocated memory
        free_matrix(A, size);
        free_matrix(B, size);
        free_matrix(C, size);
    }

    fclose(file);
    return 0;
}
