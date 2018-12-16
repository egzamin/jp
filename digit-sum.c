// DigitalSum(1995) = 6, poniewaz
//    Krok 1: 1+9+9+5 => 24
//    Krok 2:     2+4 =>  6
// Sumujemy cyfry tak dlugo, az zostanie tylko jedna cyfra.

#include <stdio.h>
#include <stdlib.h> // atoi

int DigitalSum(int);

int main(int argc, char *argv[])
{
  int n = atoi(argv[1]), r;

  r = DigitalSum(n);
  printf("\tDigitalSum(%d) = %d\n", n, r);
}

int DigitalSum(int n)
{
  if (n < 10)
    return n;
  else
    return DigitalSum(n % 10 + DigitalSum(n / 10));
}
