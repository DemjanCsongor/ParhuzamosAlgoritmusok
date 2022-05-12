using System;
using System.Diagnostics;

namespace LagrangeInterpolacio_seq
{
    class Program
    {
        public static void Main(String[] args)
        {
            Data[] f = {new Data(0, 2),
                new Data(1, 3),
                new Data(2, 12),
                new Data(5, 147)};

            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start();

            Console.Write("Value of f(3) is : " +
                          (int)interpolate(f, 3, 4));

            stopwatch.Stop();
            TimeSpan stopwatchElapsed = stopwatch.Elapsed;
            Console.Write("\nA szamitas ideje: ");
            Console.WriteLine(stopwatchElapsed.TotalMilliseconds);
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

        static double interpolate(Data[] f,
                          int xi, int n)
        {
            double result = 0;

            for (int i = 0; i < n; i++)
            {
                double term = f[i].y;
                for (int j = 0; j < n; j++)
                {
                    if (j != i)
                        term = term * (xi - f[j].x) /
                                  (f[i].x - f[j].x);
                }

                result += term;
            }
            return result;
        }
    }
}
