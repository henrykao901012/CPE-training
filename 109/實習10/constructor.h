#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H

#include "operator.h"
#include "tool.h"
#include <iostream>
#include <string>
using namespace std;

bigint::bigint()
{
    size = 100;
    array_pointer = new int[100];
    zero();
}
bigint::bigint(int value, int get)
{
    size = get;
    array_pointer = new int[size];
    zero();
    if (value > 0)
        sign = 1;
    else
        sign = -1;
    digits = 0;
    for (int t = value * sign; t > 0; t /= 10)
        digits++;
    for (int i = digits - 1; i >= 0; i--, value /= 10)
        array_pointer[i] = value * sign % 10;
}
bigint::bigint(string s, int get)
{
    size = get;
    array_pointer = new int[size];
    zero();
    if (s[0] == '+')
        sign = 1;
    else
        sign = -1;
    int sum = countzero(s);
    digits = s.length() - sum - 1;
    for (int i = 0; i < digits; i++)
        array_pointer[i] = s[i + sum + 1] - '0';
}
bigint::bigint(bigint &x)
{
    size = x.size;
    digits = x.digits;
    sign = x.sign;
    array_pointer = new int[size];
    for (int i = 0; i < size; i++)
        array_pointer[i] = x.array_pointer[i];
}
bigint::~bigint()
{
    delete[] array_pointer;
    size = digits = sign = 0;
    array_pointer = NULL;
}

#endif