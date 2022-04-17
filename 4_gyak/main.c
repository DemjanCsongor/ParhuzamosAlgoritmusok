#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define randomnumber(min, max) \
        ((rand() % (int)(((max) + 1) - (min))) + (min))

int main() {
    int n = 0;
    int t[n];
    int i = 0;

    printf("Tomb elemeinek szama:");
    scanf("%d", &n);

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        t[i] = randomnumber(0, 10);
    }

    printf("\nTomb elemei: ");
    for (i = 0; i < n; i++) {
        printf("%d  ", t[i]);
    }

    int product = t[0];
    for (i = 1; i < n; i++) {
        product = product * t[i];
    }
    printf("\nA tomb elemeinek szorzata: %d\n", product);
}
