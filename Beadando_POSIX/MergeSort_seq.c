#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int GenerateRandomNumber(unsigned int lower_limit, unsigned int upper_limit);
void merge(int arr[], int p, int q, int r);
void mergeSort(int arr[], int l, int r);

#define LENGTH 100000
#define UPPER_LIM 10000
#define LOWER_LIM  1

int arr[LENGTH];

int main() {

    srand(time(NULL));
    clock_t start, end;
    double time_spent;

    for (int i = 0; i < LENGTH; i ++) {
        arr[i] = GenerateRandomNumber(LOWER_LIM, UPPER_LIM);
    }

    start = clock();

    mergeSort(arr, 0, LENGTH - 1);

    end = clock();

    time_spent = (double) (end - start) / CLOCKS_PER_SEC;
    printf("A szamitas ideje: %f sec.", time_spent);
}

int GenerateRandomNumber(unsigned int lower_limit, unsigned int upper_limit) {
    return lower_limit + (upper_limit - lower_limit) * ((double) rand() / RAND_MAX);
}

void merge(int arr[], int p, int q, int r) {

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
    if (l < r) {

        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}
