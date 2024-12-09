
typedef struct
{
    int licznik;
    int mianownik;
} liczba_wymierna;

liczba_wymierna add(liczba_wymierna, liczba_wymierna);

liczba_wymierna sub(liczba_wymierna, liczba_wymierna);

liczba_wymierna mul(liczba_wymierna, liczba_wymierna);

liczba_wymierna dvd(liczba_wymierna, liczba_wymierna);

liczba_wymierna inv(liczba_wymierna);

liczba_wymierna neg(liczba_wymierna);

liczba_wymierna sqr(liczba_wymierna);

int num(liczba_wymierna);

int den(liczba_wymierna);
