#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sum(int array[]);
int max(int array[]);
int min(int array[]);

int main (){
    int i;
    int array[8] = {5,11,2,321,54,765,9,876};
    for (i=0;i<8;i++)
    {
        printf("%d\n",array[i]);

    }
    int osszeg = sum(array);
    printf("\nA tomb elemeinek osszege: %d",osszeg);
    int maximum = max(array);
    printf("\nA tomb maximuma : %d",array[maximum]);
    int minimum = min(array);
    printf("\n A tomb minimuma: %d",array[minimum]);
}

int sum(int array[]){
    int sum = 0;

    for(int i = 0;i<8;i++){
        sum+=array[i];
    }
    return sum;
}

int max(int array[]){
    int max = 0;
    for (int i = 0;i<8;i++){
        if (array[i]>array[max])
        {
            max=i;
        }
        
    }
    return max;
}

int min(int array[]){
    int min = 0;
    for (int i = 0;i<8;i++){
        if (array[i]<array[min])
        {
            min=i;
        }
        
    }
    return min;
}
