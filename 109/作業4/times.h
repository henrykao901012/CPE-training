#ifndef TIMES_H
#define TIMES_H

#include "add.h"
#include "bigint_end.h"
#include "constructor.h"
#include "overloading.h"
#include "tool.h"
#include <iostream>
#include <string>
using namespace std;
void bigint::times(int value)
{
    bigint t(value);
    times(t);
}
void bigint::times(string s)
{
    bigint t(s);
    times(t);
}
void bigint::times(bigint &x)
{
    bigint t;
    t.digits = digits + x.digits - 1;
    for (int i = 0; i < x.digits; i++)
        for (int j = 0; j < digits; j++)
            t.array_pointer[i + j] += array_pointer[j] * x.array_pointer[i];
    t.reverse();
    t.carry();
    t.sign = sign * x.sign;
    *this = t;
}

#endif
