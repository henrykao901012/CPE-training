#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H

#include "bigint.h"
#include "function.h"
#include <iostream>
#include <string>
using namespace std;

bigint::bigint()
{
    size = 100;
    array_pointer = new int[100];
    zero();
    digits = 0;
}
bigint::bigint(int value, int get)
{
    size = get;
    array_pointer = new int[size];
    zero();
    digits = 0;
    for (int t = value; t > 0; t /= 10)
        digits++;
    for (int i = digits - 1; i >= 0; i--, value /= 10)
        array_pointer[i] = value % 10;
    if (digits > size)
        size = digits + 100;
}
bigint::bigint(string s, int get)
{
    size = get;
    array_pointer = new int[size];
    zero();
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
            sum++;
        else
            break;
    }
    digits = s.length() - sum;
    for (int i = 0; i < digits; i++)
        array_pointer[i] = s[i + sum] - '0';
}
bigint::bigint(bigint &x)
{
    size = x.size;
    digits = x.digits;
    array_pointer = new int[size];
    for (int i = 0; i < size; i++)
        array_pointer[i] = x.array_pointer[i];
}
bigint::~bigint()
{
    delete[] array_pointer;
    size = digits = 0;
    array_pointer = NULL;
}

#endif