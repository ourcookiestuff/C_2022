#include "liczby_wymierne.h"
//#define GCD_RECURSIVE 1

int gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b, a%b);
    }
}

void skracja(liczba_wymierna * a)
{
    int nwd;
    nwd = gcd(a->licznik,a->mianownik);
    
    a->licznik = a->licznik/nwd;
    a->mianownik = a->mianownik/nwd;
}

liczba_wymierna add(liczba_wymierna p, liczba_wymierna q)
{
    liczba_wymierna r;
    
    r.licznik = p.licznik * q.mianownik + p.mianownik * q.licznik;
    r.mianownik = p.mianownik*q.mianownik;
    
    skracja(&r);
    
    return r;
}

liczba_wymierna sub(liczba_wymierna p, liczba_wymierna q)
{
    liczba_wymierna r;
    
    // a/b - c/d = (a*d - c*b)/(b*d)
    
    r.licznik = p.licznik * q.mianownik - p.mianownik * q.licznik;
    r.mianownik = p.mianownik*q.mianownik;
    
    skracja(&r);
    
    return r;
}

liczba_wymierna mul(liczba_wymierna p, liczba_wymierna q)
{
    liczba_wymierna r;
    
    r.licznik = p.licznik*q.licznik;
    r.mianownik = p.mianownik*q.mianownik;
    
    skracja(&r);
    
    return r;
}

liczba_wymierna dvd(liczba_wymierna p, liczba_wymierna q)
{
    liczba_wymierna r;
    
    r.licznik = p.licznik*q.mianownik;
    r.mianownik = p.mianownik*q.licznik;
    
    skracja(&r);
    
    return r;
}

liczba_wymierna inv(liczba_wymierna p)
{
    liczba_wymierna r;
    
    r.licznik = p.mianownik;
    r.mianownik = p.licznik;
    
    skracja(&r);
    
    return r;
}

liczba_wymierna neg(liczba_wymierna p)
{
    liczba_wymierna r;
    
    r.licznik=(-1)*p.licznik;
    r.mianownik=p.mianownik;
    
    if(r.licznik<0 && r.mianownik<0)
    {
        r.licznik=(-1)*r.licznik;
        r.mianownik=(-1)*r.mianownik;
    }
    
    return r;
}

liczba_wymierna sqr(liczba_wymierna p)
{
    liczba_wymierna r;
    
    r.licznik = p.licznik*p.licznik;
    r.mianownik = p.mianownik*p.mianownik;
    
    skracja(&r);
    
    return r;
}

int num(liczba_wymierna p)
{
    int r;
    
    r=p.licznik;
    
    return r;
}

int den(liczba_wymierna p)
{
    int r;
    
    r=p.mianownik;
    
    return r;
}
