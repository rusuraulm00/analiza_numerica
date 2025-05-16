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

void interpolareAitkenNeville()
{
    float a = 0;
    float b = 1;
    float alpha = 0.526;
    int n = 5;
    float x[100], y[100], p[100][100];

    float h = (b - a) / n;

    for (int i = 0; i < n; i++)
    {
        x[i] = a + i * h;
    }

    for (int i = 0; i < n; i++)
    {
        p[0][i] = f(x[i]);
    }

    for (int i = 0; i <= n - 1; i++)
    {
        for (int k = 0; k <= n - i - 1; k++)
        {
            p[i + 1][k] = (p[i][k + 1] * (alpha - x[k]) - p[i][k] * (alpha - x[i + k + 1])) / (x[i + k + 1] - x[k]);
        }
    }

    std::cout << "Valoarea functiei in alpha este: " << f(alpha) << "\n";
    std::cout << "Valoarea polinomului de interpolare este: " << p[n][0] << "\n";
    std::cout << "Eroarea de interpolare in alpha este: " << abs(f(alpha) - p[n][0]) << "\n";
}

int main()
{
    // interpolareLagrange();
    // interpolareNewton();
    interpolareAitkenNeville();
    return 0;
}
