#include <iostream>
#include <cmath>

const float eps = 0.00001;
const int ITMAX = 100;

float g(float x)
{
    return exp(-x);
}

void metodaPunctuluiFix()
{
    int k = 0;
    float x = 0;

    while ((abs(g(x) - x) > eps) && k <= ITMAX)
    {
        x = g(x);
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

int main()
{
    metodaPunctuluiFix();
    return 0;
}