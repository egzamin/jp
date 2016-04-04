// Copyright Kevin Lawler, released under ISC License

#include <stdint.h>
#include <math.h>

double random_double();
void vitter(int64_t *a, int64_t n, int64_t N);
void vitter_a(int64_t *a, int64_t n, int64_t N, int64_t j);

double random_double()  // your random double function
{
  // [0,1) uniformly random double, mt19937-64.c source is fine
  // keep in mind most double-based implementations drop randomness to 52-bits
  return genrand64_real2();
}

// POTENTIAL_OPTIMIZATION_POINT: Christian Neukirchen points out we can replace exp(log(x)*y) by pow(x,y)
// POTENTIAL_OPTIMIZATION_POINT: Vitter paper points out an exponentially distributed random var can provide speed ups
// Vitter, J.S. - An Efficient Algorithm for Sequential Random Sampling - ACM Trans. Math. Software 11 (1985), 37-57.
// 'a' is space allocated for the hand
// 'n' is the size of the hand
// 'N' is the upper bound on the random card values
void vitter(int64_t *a, int64_t n, int64_t N) // Method D
{
  int64_t i = 0;
  int64_t j = -1;
  int64_t t;
  int64_t qu1 = -n + 1 + N;
  int64_t S;
  int64_t negalphainv = -13;
  int64_t threshold = -negalphainv*n;

  double nreal = n;
  double Nreal = N;
  double ninv = 1.0/n;
  double nmin1inv = 1.0/(n-1);
  double Vprime = exp(log(random_double())*ninv);

  double qu1real = -nreal + 1.0 + Nreal;
  double negSreal;
  double U;
  double X;
  double y1;
  double y2;
  double top;
  double bottom;
  double limit;

  while(n > 1 && threshold < N)
  {
    nmin1inv=1.0/(-1.0+nreal);

    while(1)
    {
      while(1)
      {
        X = Nreal * (-Vprime + 1.0);
        S = floor(X);

        if(S < qu1)
        {
          break;
        }

        Vprime = exp(log(random_double()) * ninv);
      }

      U = random_double();

      negSreal = -S;

      y1 = exp(log(U*Nreal/qu1real) * nmin1inv);

      Vprime = y1 * (-X / Nreal+1.0) * (qu1real / (negSreal + qu1real));

      if(Vprime <= 1.0)
      {
        break;
      }

      y2 = 1.0;

      top = -1.0 + Nreal;

      if(-1+n > S)
      {
        bottom = -nreal + Nreal;
        limit = -S + N;
      }
      else
      {
        bottom = -1.0 + negSreal + Nreal;
        limit = qu1;
      }

      for(t = N-1; t >= limit; t--)
      {
        y2=(y2 * top) / bottom;
        top--;
        bottom--;
      }

      if(Nreal / (-X + Nreal) >= y1 * exp(log(y2) * nmin1inv))
      {
        Vprime = exp(log(random_double()) * nmin1inv);
        break;
      }

      Vprime = exp(log(random_double()) * ninv);
    }

    j += S + 1;
    a[i++] = j;
    N = -S + (-1 + N);
    Nreal = negSreal + (-1.0 + Nreal);

    n--;
    nreal--;
    ninv = nmin1inv;

    qu1 = -S + qu1;
    qu1real = negSreal + qu1real;

    threshold += negalphainv;
  }

  if(n>1)
  {
    vitter_a(a+i,n,N,j); // if i>0 then n has been decremented
  }
  else
  {
    S = floor(N * Vprime);
    j += S + 1;
    a[i++] = j;
  }
}

void vitter_a(int64_t *a, int64_t n, int64_t N, int64_t j) // Method A
{
  int64_t S, i = 0;
  double top = N - n, Nreal = N, V, quot;

  while(n >= 2)
  {
    V = random_double();
    S=0;
    quot=top/Nreal;

    while (quot>V)
    {
      S++; top--; Nreal--;
      quot = (quot * top)/Nreal;
    }

    j+=S+1;
    a[i++]=j;
    Nreal--;
    n--;
  }

  S = floor(round(Nreal) * random_double());
  j+=S+1;
  a[i++]=j;
 }
