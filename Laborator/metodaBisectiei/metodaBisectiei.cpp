#include <iostream>
#include <cmath>

const float eps = 0.00001;
const int ITMAX = 100;

float f(float x)
{
    return x - sin(x) - 0.5;
}

int main()
{
    int k = 0;
    float a = 0, b = 3;
    float x;

    if (abs(f(a)) <= eps)
    {
        std::cout << "Radacina este x = " << a << "\n";
        return 0;
    }

    if (abs(f(b)) <= eps)
    {
        std::cout << "Radacina este x = " << b << "\n";
        return 0;
    }

    if (f(a) * f(b) > 0)
    {
        std::cout << "Nu exista radacina in [a,b] " << "\n";
    }

    if (f(a) * f(b) < 0)
    {
        x = (a + b) / 2.0;

        while (abs(f(x)) > eps && k <= ITMAX)
        {
            if (f(a) * f(x) < 0)
            {
                b = x;
            }
            else
            {
                a = x;
            }
            x = (a + b) / 2.0;
            k++;
        }

        if (k > ITMAX)
        {
            std::cout << "Nr max de iteratii depasit!";
        }
        else
        {
            std::cout << "Valoare aproxiamtiva a solutiei ecuatiei este: " << x << "\n";
            std::cout << "Nr de iteratii efectuate este: " << k << "\n";
        }
    }

    return 0;
}
