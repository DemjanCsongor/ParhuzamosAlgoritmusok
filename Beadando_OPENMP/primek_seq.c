#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void prime_number_sweep (int n_low, int n_high, int n_factor );
int prime_number ( int n );

int main ()
{
    int n_factor;
    int n_high;
    int n_low;

    n_low = 1;
    n_high = 131072;
    n_factor = 2;

    srand(time(NULL));
    clock_t start, end;
    double time_spent;

/* Idomeres inditasa */
    start = clock();

    prime_number_sweep (n_low, n_high, n_factor );

/* Idomeres vege */
    end = clock();

    time_spent = (double) (end - start) / CLOCKS_PER_SEC;
    printf("A szamitas ideje: %f sec.", time_spent);


    return 0;
}
/* prime_number ismetlodo hivasai tortenik */
void prime_number_sweep (int n_low, int n_high, int n_factor )
{
    int n;
    int primes;

    printf ( "\n" );
    printf ( "         N        Pi\n" );
    printf ( "\n" );

    n = n_low;

    while (n <= n_high )
    {
        primes = prime_number ( n );

        printf ( "  %8d  %8d \n", n, primes);

        n = n * n_factor;
    }

    return;
}
/* visszaadja a primek szamat 1 es N kozott */
int prime_number ( int n )

{
    int i;
    int j;
    int prime;
    int sum = 0;

    for ( i = 2; i <= n; i++ )
    {
        prime = 1;

        for ( j = 2; j < i; j++ )
        {
            if ( i % j == 0 )
            {
                prime = 0;
                break;
            }
        }
        sum = sum + prime;
    }
    return sum;
}