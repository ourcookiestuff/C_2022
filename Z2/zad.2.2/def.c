int fib_i(int liczba1)
{
    if(liczba1==0||liczba1==1)
    {
        return 1.0;
    }
    else
    {
        return fib_i(liczba1-1)+fib_i(liczba1-2);
    }
}

double fib_f(int liczba1)
{
    if(liczba1==0||liczba1==1)
    {
        return 1.0;
    }
    else
    {
        return fib_f(liczba1-1)+fib_f(liczba1-2);
    }
}

int silnia_i(int liczba1)
{
    if(liczba1<=1)
        return 1;
    return liczba1*silnia_i(liczba1-1);
}

double silnia_f(int liczba1)
{
    if(liczba1<=1)
        return 1;
    return liczba1*silnia_f(liczba1-1);
}

int silnia2_i(int liczba1)
{
    if(liczba1<=1)
        return 1;
    return liczba1*silnia2_i(liczba1-2);
}

double silnia2_f(int liczba1)
{
    if(liczba1<=1)
        return 1;
    return liczba1*silnia2_f(liczba1-2);
}
