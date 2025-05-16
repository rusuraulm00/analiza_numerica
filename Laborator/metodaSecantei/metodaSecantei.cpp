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

void metodaSecantei()
{
    const double eps = 0.00001;
    const int ITMAX = 100;

    double x_0 = 0;
    double x_1 = 1;
    double x;

    int k = 0;

    while (abs(f(x_1)) > eps && k <= ITMAX)
    {
        x = x_1 - f(x_1) * (x_1 - x_0) / (f(x_1) - f(x_0));
        x_0 = x_1;
        x_1 = x;
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
    metodaSecantei();
    return 0;
}