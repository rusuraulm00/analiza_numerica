#include <iostream>
#include <cmath>

double f(double x)
{
    return cos(x);
}

void interpolareNewton()
{
    float a = 0;
    float b = 1;
    float alpha = 0.526;
    float n = 5;
    float x[100], y[100], d[100][100];

    float h = (b - a) / n;

    for (int i = 0; i <= n; i++)
    {
        x[i] = a + i * h;
        y[i] = f(x[i]);
        d[i][0] = y[i];
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 0; i <= n - k; i++)
        {
            d[i][k] = (d[i + 1][k - 1] - d[i][k - 1]) / (x[i + k] - x[i]);
        }
    }

    float S = d[0][0];
    float P;

    for (int k = 1; k <= n; k++)
    {
        P = 1;
        for (int i = 0; i <= k - 1; i++)
        {
            P = P * (alpha - x[i]);
        }
        S = S + d[0][k] * P;
    }
    std::cout << "Valoarea functiei in alpha este: " << f(alpha) << "\n";
    std::cout << "Valoarea polinomului de interpolare este: " << S << "\n";
    std::cout << "Eroarea de interpolare in alpha este: " << abs(f(alpha) - S) << "\n";
}

int main()
{
    interpolareNewton();
    return 0;
}