#include <iostream>
#include <cmath>

float f(float x)
{
    return cos(x);
}

void interpolareAitkenNeville()
{
    float a = 0;
    float b = 1;
    float alpha = 0.526;
    int n = 5;
    float x[100], y[100], p[100][100];

    float h = (b - a) / n;

    for (int i = 0; i <= n; i++)
    {
        x[i] = a + i * h;
    }

    for (int i = 0; i <= n; i++)
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
    interpolareAitkenNeville();
    return 0;
}