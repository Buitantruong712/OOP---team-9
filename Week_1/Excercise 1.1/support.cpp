#include "support.h"

int GCD(int a, int b) {
    if (a == b)
        return a;
    else if (a > b)
        return GCD(a - b, b);
    else
        return GCD(a, b - a);
}