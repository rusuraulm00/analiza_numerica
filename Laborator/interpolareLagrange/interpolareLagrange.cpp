#include <iostream>
#include <cmath>

double f(double x)
{
    return cos(x);
}

void interpolareLagrange()
{
    double a = 0;
    double b = 1;
    double alpha = 0.526;
    double n = 5;
    double x[100], y[100];

    double h = (b - a) / n;

    for (int i = 0; i <= n; i++)
    {
        x[i] = a + i * h;
        y[i] = f(x[i]);
    }

    double S = 0;
    double P;

    for (int i = 0; i <= n; i++)
    {
        P = 1;
        for (int k = 0; k <= n; k++)
        {
            if (k != i)
            {
                P = P * (alpha - x[k]) / (x[i] - x[k]);
            }
        }
        S = S + y[i] * P;
    }

    std::cout << "Valoarea functiei in alpha este: " << f(alpha) << "\n";
    std::cout << "Valoarea polinomului de interpolare este: " << S << "\n";
    std::cout << "Eroarea de interpolare in alpha este: " << abs(f(alpha) - S) << "\n";
}

int main()
{
    interpolareLagrange();
    return 0;
}