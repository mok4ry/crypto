#ifndef CRYPTOMATH_H
#define CRYPTOMATH_H

#ifndef BOOL
#define BOOL
typedef enum { false, true } bool;
#endif

extern bool are_coprime(int a, int b);

extern int gcd(int a, int b);

#endif