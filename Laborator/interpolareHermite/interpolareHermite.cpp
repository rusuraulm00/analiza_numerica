#include <iostream>
#include <cmath>

float f(float x)
{
    return cos(x);
}

float g(float x)
{
    return -sin(x);
}

void interpolareHermite()
{
    float a = 0;
    float b = 1;
    float alpha = 0.526;
    float n = 5;
    float x[100], y[100], z[100];

    float h = (b - a) / n;

    for (int i = 0; i <= n; i++)
    {
        x[i] = a + i * h;
        y[i] = f(x[i]);
        z[i] = g(x[i]);
    }

    float S = 0;

    for (int k = 0; k <= n; k++)
    {
        float P1 = 1;
        for (int i = 0; i <= n; i++)
        {
            if (i != k)
            {
                P1 = P1 * (x[k] - x[i]);
            }
        }

        float s = 0;
        for (int j = 0; j <= n; j++)
        {
            if (j != k)
            {
                float P2 = 1;
                for (int i = 0; i <= n; i++)
                {
                    if (i != k && i != j)
                    {
                        P2 = P2 * (x[k] - x[i]);
                    }
                }
                s = s + P2;
            }
        }
        s = s * 2;
        float P3 = 1;
        for (int i = 0; i <= n; i++)
        {
            if (i != k)
            {
                P3 = P3 * ((alpha - x[i]) / (x[k] - x[i]));
            }
        }
        S = S + (y[k] + (alpha - x[k]) * z[k] - (s / P1) * (alpha - x[k]) * y[k]) * P3 * P3;
    }
    std::cout << "Valoarea functiei in alpha este: " << f(alpha) << "\n";
    std::cout << "Valoarea polinomului de interpolare este: " << S << "\n";
    std::cout << "Eroarea de interpolare in alpha este: " << abs(f(alpha) - S) << "\n";
}

int main()
{
    interpolareHermite();
    return 0;
}