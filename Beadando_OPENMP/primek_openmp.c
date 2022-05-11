# include <stdio.h>
# include <omp.h>

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

    omp_set_dynamic(0);
    omp_set_num_threads(6); // thread-ek szamanak megadasa

    double start, end;

/* Idomeres inditasa */
    start = omp_get_wtime();

    prime_number_sweep (n_low, n_high, n_factor );

/* Idomeres vege */
    end = omp_get_wtime();
    printf("A szamitas ideje: %f sec.", end-start);


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

# pragma omp parallel \
  shared ( n ) \
  private ( i, j, prime )


# pragma omp for reduction ( + : sum )
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