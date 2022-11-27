#ifndef FUNCTION_H
#define FUNCTION_H

#include "bigint.h"
#include "constructor.h"
#include <iostream>
#include <string>
using namespace std;
int max(int a, int b)
{
    return a >= b ? a : b;
}
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
void bigint::zero()
{
    for (int i = 0; i < size; i++)
        array_pointer[i] = 0;
}
void bigint::reverse()
{
    for (int i = 0; i < digits / 2; i++)
        swap(array_pointer[i], array_pointer[digits - i - 1]);
}
void bigint::carry()
{
    for (int i = 0; i < digits; i++)
    {
        if (array_pointer[i] > 9)
        {
            array_pointer[i] -= 10;
            array_pointer[i + 1]++;
            if (i == digits - 1)
                digits++;
        }
    }
}
void bigint::printnum()
{

    if (digits == 0)
        cout << 0;
    for (int i = 0; i < digits; i++)
        cout << array_pointer[i] << " ";
    cout << "\n";
}
///////////////////////////////////////////////////
void bigint::add(int value)
{
    int i;
    reverse();
    for (i = 0; value > 0; i++, value /= 10)
        array_pointer[i] += value % 10;
    digits = max(digits, i);
    carry();
    reverse();
}
void bigint::add(string s)
{
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
            sum++;
        else
            break;
    }
    reverse();
    digits = max(digits, s.length() - sum);
    for (int i = 0; i < digits; i++)
        array_pointer[digits - i - 1] += s[i + sum] - '0';
    carry();
    reverse();
}
void bigint::add(bigint &x)
{
    reverse();
    x.reverse();
    digits = max(digits, x.digits);
    for (int i = 0; i < digits; i++)
        array_pointer[i] += x.array_pointer[i];
    carry();
    reverse();
    x.reverse();
}
#endif