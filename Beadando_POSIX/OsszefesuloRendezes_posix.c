#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

/* Változók definiálása */
#define LENGTH 100000
#define UPPER_LIM 10000
#define LOWER_LIM  1
#define NUM_THREADS 4

/* Származtatott változók  */
const int NUMBERS_PER_THREAD = LENGTH / NUM_THREADS;
const int OFFSET = LENGTH % NUM_THREADS;
int array[LENGTH];

int GenerateRandomNumber(unsigned int lower_limit, unsigned int upper_limit);
void MergeSort(int arr[], int left, int right);
void Merge(int arr[], int left, int middle, int right);
void* ThreadMergeSort(void* arg);
void MergeSectionsOfArray(int arr[], int number, int aggregation);

int main()
{
    srand(time(NULL));
    clock_t start, end;
    double time_spent;

    /*  Tömb feltöltése random számokkal */
    for (int i = 0; i < LENGTH; i ++) {
        array[i] = GenerateRandomNumber(LOWER_LIM, UPPER_LIM);
    }

    pthread_t threads[NUM_THREADS];

    /* Időmérés elindítása */
    start = clock();

    /* Thread-ek készítése */
    for (long i = 0; i < NUM_THREADS; i ++) {
        int rc = pthread_create(&threads[i], NULL, ThreadMergeSort, (void *) i);
        if (rc){
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    
    for(long i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    MergeSectionsOfArray(array, NUM_THREADS, 1);

    /* Időmérés vége */
    end = clock();

    time_spent = (double) (end - start) / CLOCKS_PER_SEC;
    printf("A szamitas ideje: %f sec.", time_spent);

    return 0;
}

/* A megadott intervallumon belül random számok generálása */
int GenerateRandomNumber(unsigned int lower_limit, unsigned int upper_limit) {
    return lower_limit + (upper_limit - lower_limit) * ((double)rand() / RAND_MAX);
    //return rand() % upper_limit + lower_limit;
}

/* Helyileg rendezett szakaszok egyesítése */
void MergeSectionsOfArray(int arr[], int number, int aggregation) {
    for(int i = 0; i < number; i = i + 2) {
        int left = i * (NUMBERS_PER_THREAD * aggregation);
        int right = ((i + 2) * NUMBERS_PER_THREAD * aggregation) - 1;
        int middle = left + (NUMBERS_PER_THREAD * aggregation) - 1;
        if (right >= LENGTH) {
            right = LENGTH - 1;
        }
        Merge(arr, left, middle, right);
    }
    if (number / 2 >= 1) {
        MergeSectionsOfArray(arr, number / 2, aggregation * 2);
    }
}

/* Hozzárendeli a munkát minden thread-nek, hogy összefésülő rendezést hajtsanak végre*/
void *ThreadMergeSort(void* arg)
{
    int thread_id = (long)arg;
    int left = thread_id * (NUMBERS_PER_THREAD);
    int right = (thread_id + 1) * (NUMBERS_PER_THREAD) - 1;
    if (thread_id == NUM_THREADS - 1) {
        right += OFFSET;
    }
    int middle = left + (right - left) / 2;
    if (left < right) {
        MergeSort(array, left, right);
        MergeSort(array, left + 1, right);
        Merge(array, left, middle, right);
    }
    return NULL;
}

/* Összefésülő rendezés */
void MergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        MergeSort(arr, left, middle);
        MergeSort(arr, middle + 1, right);
        Merge(arr, left, middle, right);
    }
}

/* Merge function */
void Merge(int arr[], int left, int middle, int right) {
    int i = 0, j = 0, k = 0;
    int left_length = middle - left + 1;
    int right_length = right - middle;
    int left_array[left_length];
    int right_array[right_length];
    
    /* Értékek másolása a bal tömbbe */
    for (i = 0; i < left_length; i ++) {
        left_array[i] = arr[left + i];
    }
    
    /* Értékek másolása a jobb tömbbe */
    for (j = 0; j < right_length; j ++) {
        right_array[j] = arr[middle + 1 + j];
    }
    
    i = 0;
    j = 0;
    /* Választ a jobb és bal tömbök közül és másolja az értékeket */
    while (i < left_length && j < right_length) {
        if (left_array[i] <= right_array[j]) {
            arr[left + k] = left_array[i];
            i ++;
        } else {
            arr[left + k] = right_array[j];
            j ++;
        }
        k ++;
    }
    
    /* A fennmaradt értékeket másolja a tömbbe */
    while (i < left_length) {
        arr[left + k] = left_array[i];
        k ++;
        i ++;
    }
    while (j < right_length) {
        arr[left + k] = right_array[j];
        k ++;
        j ++;
    }
}