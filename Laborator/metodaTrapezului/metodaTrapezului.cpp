#include <iostream>
#include <cmath>

float f1(float x)
{
    return 1 / (1 + x);
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

int main()
{
    metodaTrapezului();
    return 0;
}