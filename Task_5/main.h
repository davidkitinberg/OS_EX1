#ifndef MAIN_H
#define MAIN_H

// Struct to hold the array and its size
typedef struct {
    int* data;
    int size;
} IntArray;

// Function declarations
int max_subarray_n3(const int* array, int n);
int max_subarray_n2(const int* array, int n);
int max_subarray_n(const int* array, int n);
IntArray generate_random_array(int size, int seed);

#endif // MAIN_H
