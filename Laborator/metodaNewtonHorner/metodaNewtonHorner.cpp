#include <iostream>
#include <cmath>

double f(double x)
{
    return x * exp(x) - 1;
}

double g(double x)
{
    return (x + 1) * exp(x);
}

int n = 3;
double a[10] = {1, 0, -3, 1};

double p(double x)
{
    int i;
    double sum = 0;

    for (i = 0; i <= n; i++)
    {
        sum = sum + a[i] * pow(x, n - i);
    }

    return sum;
}

void metodaNewtonHorner()
{
    const double eps = 0.00001;
    const int ITMAX = 100;

    double b[10], c[10];
    int k = 0;
    double x = 0.1;

    while (abs(p(x)) > eps && k <= ITMAX)
    {

        b[0] = a[0];
        for (int i = 1; i <= n; i++)
        {
            b[i] = a[i] + x * b[i - 1];
        }

        c[0] = b[0];
        for (int i = 1; i <= n; i++)
        {
            c[i] = b[i] + x * c[i - 1];
        }

        x = x - b[n] / c[n - 1];
        k++;
    }

    if (k > ITMAX)
    {
        std::cout << "Nr maxim de iteratii depasit!";
    }
    else
    {
        std::cout << "Valoarea aproximativa a solutiei este: " << x << "\n";
        std::cout << "Nr de iteratii efectuate este: " << k << "\n";
    }
}

int main()
{
    metodaNewtonHorner();
    return 0;
}