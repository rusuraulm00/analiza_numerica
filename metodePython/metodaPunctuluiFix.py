from math import exp

eps = 0.00001
ITMAX = 100

k = 0
x = 0

while abs(exp(-x) - x) > eps and k < ITMAX:
    x = exp(-x)
    k += 1

print(f"valoarea aproximativa a solutiei ecuatiei este: {x}")
print(f"nr de iteratii este: {k}")