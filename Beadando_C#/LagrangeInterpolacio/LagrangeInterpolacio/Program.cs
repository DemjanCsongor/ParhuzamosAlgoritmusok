using System;
using System.Threading;
using System.Threading.Tasks;
using System.Diagnostics;

namespace LagrangeInterpolacio
{
    class Program
    {
        static void Main(string[] args)
        {

            /* Egy tömb létrehozása 4 ismert elemmel */
            Data[] f = {new Data(0, 2),
                new Data(1, 3),
                new Data(2, 12),
                new Data(5, 147)};

            /* Idomeres Start */
            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start();

            /* Az interpolate metódus használata */
            Console.Write("Value of f(3) is : " +
                          (int)interpolate(f, 3, 4));

            /* Idomeres Vege */
            stopwatch.Stop();
            Console.Error.WriteLine("\nSequential loop time in milliseconds: {0}", stopwatch.ElapsedMilliseconds);


            Console.ReadLine();
        }

        class Data
        {
            public int x, y;
            public Data(int x, int y)
            {
                this.x = x;
                this.y = y;
            }
        };
        /* Langrange Interpolációs képlet paralelizálva */
        static double interpolate(Data[] f,
                          int xi, int n)
        {
            double result = 0;
            var options = new ParallelOptions()
            {
                MaxDegreeOfParallelism = 8 // Threadek számának meghatározása
            };
            Parallel.For(0, n, options, i =>
            {
                double term = f[i].y;
                for (int j = 0; j < n; j++)
                {
                    if (j != i)
                        term = term * (xi - f[j].x) /
                                  (f[i].x - f[j].x);
                }

                result += term;
            });
            return result;
        }
    }
}
