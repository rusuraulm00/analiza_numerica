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

float f1(float x)
{
    return 1 / (1 + x);
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

void metodaPunctuluiMediu()
{
    float a = 0, b = 1, eps = 0.00001, x[100];
    int n = 1;
    float h;
    float S[100], s;

    S[1] = (b - a) * f1((a + b) / 2);
    do
    {
        n += 1;
        h = (b - a) / n;
        for (int i = 0; i <= n; i++)
        {
            x[i] = a + i * h;
        }
        s = 0;
        for (int i = 0; i <= n - 1; i++)
        {
            s = s + f1((x[i] + x[i + 1]) / 2);
        }
        S[n] = (b - a) / n * s;
    } while (abs(S[n] - S[n - 1]) > eps);

    std::cout << "Valoarea aproximativa a integralei este: " << S[n] << '\n';
    std::cout << n << '\n';
}

void metodaTrapezului()
{
    float a = 0, b = 1, eps = 0.00001, x[100];
    int n = 1;
    float h;
    float S[100], s;

    S[1] = (b - a) / 2 * (f1(a) + f1(b));
    do
    {
        n += 1;
        h = (b - a) / n;
        for (int i = 0; i <= n; i++)
        {
            x[i] = a + i * h;
        }
        s = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            s = s + f1(x[i]);
        }
        S[n] = (b - a) / (2 * n) * (f1(a) + f1(b) + s * 2);

    } while (abs(S[n] - S[n - 1]) > eps);

    std::cout << "Valoarea aproximativa a integralei este: " << S[n] << '\n';
    std::cout << n << '\n';
}

void metodaSimpson()
{
    float a = 0, b = 1;
    float eps = 0.00001;
    float s[4], S[30], h, x[30];
    int n = 1;
    S[1] = ((b - a) / 6) * (f(a) + f(b) + 4 * f((a + b) / 2));
    do
    {
        n++;
        h = (b - a) / n;
        for (int i = 0; i <= n; i++)
        {
            x[i] = a + i * h;
        }
        s[1] = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            s[1] = s[1] + f(x[i]);
        }
        s[2] = 0;
        for (int i = 0; i <= n - 1; i++)
        {
            s[2] = s[2] + f((x[i] + x[i + 1]) / 2);
        }
        S[n] = (b - a) / (6 * n) * (f(a) + f(b) + 2 * s[1] + 4 * s[2]);
    } while (abs(S[n] - S[n - 1] >= eps));
    std::cout << "Valoarea aproximativa a integralei este: " << S[n] << '\n';
    std::cout << n << '\n';
}

int main()
{
    // interpolareHermite();
    // metodaPunctuluiMediu();
    // metodaTrapezului();
    metodaSimpson();
    return 0;
}