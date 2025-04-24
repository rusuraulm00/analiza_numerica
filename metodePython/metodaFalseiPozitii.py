from math import sin

def f(x):
    return x - sin(x) - 0.5

eps = 0.00001
ITMAX = 100

a = 0
b = 3
k = 0

if abs(f(a)) <= eps:
    print(f"radacina este x = : {a}")

if abs(f(b)) <= eps:
    print(f"radacina este x = : {b}")

if f(a) * f(b) > 0:
    print("nu exista radacini in intervalul [a,b]")

if f(a) * f(b) < 0:
    x = b - (f(b) * (a - b)) / (f(a) - f(b))
    while abs(f(x)) > eps and k <= ITMAX:
        if f(a) * f(x) < 0:
            b = x
        else:
            a = x
        x = b - (f(b) * (a - b)) / (f(a) - f(b))
        k += 1

    if k > ITMAX:
        print("nr maxim de iteratii a fost depasit")
    else:
        print(f"valoarea aproximativa a ecuatiei este x = : {x}")
        print(f"nr de iteratii efectuate este: {k}")