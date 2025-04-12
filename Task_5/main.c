#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

// O(n^3)
int max_subarray_n3(const int* array, int n) {
    int best = 0;
    for (int a = 0; a < n; a++) {
        for (int b = a; b < n; b++) {
            int sum = 0;
            for (int k = a; k <= b; k++) {
                sum += array[k];
            }
            if (sum > best) best = sum;
        }
    }
    return best;
}

// O(n^2)
int max_subarray_n2(const int* array, int n) {
    int best = 0;
    for (int a = 0; a < n; a++) {
        int sum = 0;
        for (int b = a; b < n; b++) {
            sum += array[b];
            if (sum > best) best = sum;
        }
    }
    return best;
}

// O(n) - Kadane's algorithm
int max_subarray_n(const int* array, int n) {
    int best = 0, sum = 0;
    for (int k = 0; k < n; k++) {
        sum = array[k] > (sum + array[k]) ? array[k] : (sum + array[k]);
        best = best > sum ? best : sum;
    }
    return best;
}


// Separate function for array generation
IntArray generate_random_array(int size, int seed) {
    IntArray arr;
    arr.data = malloc(size * sizeof(int));
    if(arr.data == NULL) {
        fprintf(stderr, "Malloc failed\n");
        free(arr.data);
        exit(1);
    }

    arr.size = size;
    srand(seed); // Initialize random seed

    for (int i = 0; i < size; i++) {
        arr.data[i] = rand() % 100 - 25; // [-25, 74]
    }
    return arr;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <seed> <array_size>\n", argv[0]);
        return 1;
    }

    // Atoi arguments from the commend line argc
    int seed = atoi(argv[1]);
    int size = atoi(argv[2]);

    // Generate array in its own profiled function
    IntArray arr = generate_random_array(size, seed);

    // O(n^3)
    int result1 = max_subarray_n3(arr.data, arr.size);
    printf("The result for O(n^3) is %d \n",result1);
    // O(n^2)
    int result2 = max_subarray_n2(arr.data, arr.size);
    printf("The result for O(n^2) is %d \n",result2);
    // O(n)
    int result3 = max_subarray_n(arr.data, arr.size);
    printf("The result for O(n) is %d \n",result3);

    free(arr.data);

    return 0;
}
