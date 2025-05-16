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

void metodaNewtonModificata()
{
    const double eps = 0.00001;
    const int ITMAX = 100;
    double x = 1;

    int k = 0;
    double d = g(x);

    while (abs(f(x)) > eps && k <= ITMAX)
    {
        x = x - f(x) / d;
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
    metodaNewtonModificata();
    return 0;
}