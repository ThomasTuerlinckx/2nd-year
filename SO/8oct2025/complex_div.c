#include "complex.h"

complex *complex_div(complex *z, complex *w) {
  double denom = w->x * w->x + w->y * w->y;
  double real = (z->x * w->x + z->y * w->y) / denom;
  double imag = (z->y * w->x - z->x * w->y) / denom;
  return complex_new(real, imag);
}
