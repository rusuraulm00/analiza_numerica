#include <iostream>
#include <cmath>

float f(float x)
{
    return 1 / (1 + x);
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
    metodaSimpson();
    return 0;
}