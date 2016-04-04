/*
  Sprawdzić, wykonując odpowiednie testy, jak działają operacje rzutowania
  z typów „mniejszych” do „większych” i odwrotnie.
  Na przykład, czemu są równe:
    (int)FLT_MAX
    (int)DBL_MAX
    (double)LDBL_MAX
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
  printf("FLT_MAX -> (int)FLT_MAX:\n%e -> %i\n\n", FLT_MAX, (int)FLT_MAX);
  // wyznacza maksymalna (czyli jak najblizsza zadanej(float)) liczbe w innym typie (int)
  printf("INT_MAX -> (float)INT_MAX:\n%i -> %e\n\n", INT_MAX, (float)INT_MAX);
  // wypisuje maksymalna wartosc inta (float > int)
  printf("DBL_MAX -> (int)DBL_MAX:\n%e -> %i\n", DBL_MAX, (int)DBL_MAX);
  // wyznacza maksymalna (czyli jak najblizsza zadanej(double)) liczbe w innym typie (int)
  printf("Wartosc double max wychodzi poza maksymalna wartosc int. Wypisywane jest wartosc maksymalna int.\n\n");
  printf("INT_MAX -> (double)INT_MAX:\n%i -> %e\n\n", INT_MAX, (double)INT_MAX);
  // wypisuje maksymalna wartosc inta (double > int)
  printf("LDBL_MAX -> (double)LDBL_MAX:\n%Le -> %e\n\n", LDBL_MAX, (double)LDBL_MAX);
  printf("(double)LDBL_MAX podzielone przez 2:\n %e \n\n", (double)LDBL_MAX/2);
  printf("(double)LDBL_MAX podzielone przez 4:\n %e \n\n", (double)LDBL_MAX/4);
  // wypisuje infinity
  printf("LONG_MAX -> (float)LONG_MAX:\n%li -> %e\n\n", LONG_MAX, (float)LONG_MAX);
  // wypisuje maksymalna wartosc longa(float > long)
  printf("INT_MAX -> (float)INT_MAX:\n%i -> %e\n\n", INT_MAX, (float)INT_MAX);
  // wypisuje maksymalna wartosc inta (float > int)
}
