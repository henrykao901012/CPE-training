#ifndef TOOL_H
#define TOOL_H

#include "bigint_end.h"
#include "constructor.h"
#include <iostream>
#include <string>
using namespace std;
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
    digits = 0;
    sign = 1;
}
void bigint::reverse()
{
    for (int i = 0; i < digits / 2; i++)
        swap(array_pointer[i], array_pointer[digits - i - 1]);
}
int bigint::countzero()
{
    int sum = 0;
    for (int i = 0; i < digits; i++)
    {
        if (array_pointer[i] == 0)
            sum++;
        else
            break;
    }
    return sum;
}
int bigint::countzero(string s)
{
    int sum = 0;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == '0')
            sum++;
        else
            break;
    }
    return sum;
}
void bigint::carry()
{
    int initial_digits = digits;
    for (int i = 0; i < digits && i != initial_digits; i++)
    {
        while (array_pointer[i] > 9)
        {
            array_pointer[i] -= 10;
            array_pointer[i + 1]++;
            if (i == digits - 1)
            {
                digits++;
                break;
            }
        }
        while (array_pointer[i] < 0)
        {
            array_pointer[i] += 10;
            array_pointer[i + 1]--;
            if (i == digits - 1)
            {
                digits++;
                break;
            }
        }
    }
    reverse();
    int sum = countzero();
    digits -= sum;
    for (int i = 0; i < digits; i++)
        array_pointer[i] = array_pointer[i + sum];
    for (int i = digits; i < size; i++)
        array_pointer[i] = 0;
    if (array_pointer[0] >= 0)
        sign = 1;
    else
    {
        sign = -1;
        reverse();
        for (int i = 0; i < digits; i++)
            array_pointer[i] *= -1;
        for (int i = 0; i < digits; i++)
        {
            if (array_pointer[i] < 0)
            {
                array_pointer[i] += 10;
                array_pointer[i + 1]--;
            }
        }
        reverse();
        int sum = countzero();
        digits -= sum;
        for (int i = 0; i < digits; i++)
            array_pointer[i] = array_pointer[i + sum];
        for (int i = digits; i < size; i++)
            array_pointer[i] = 0;
    }
}
void bigint::printnum()
{
    if (digits == 0)
        cout << 0;
    else
    {
        if (sign == 1)
            cout << "+";
        else
            cout << "-";
        for (int i = 0; i < digits; i++)
            cout << array_pointer[i];
    }
}
int bigint::getcount()
{
    return count;
}
////////////////////////////////////////////////////////////////
void bigcomplexnum::setvalue(int a, int b)
{
    x = a;
    y = b;
}
void bigcomplexnum::setvalue(bigint &a, bigint &b)
{
    x = a;
    y = b;
}
void bigcomplexnum::printnum()
{
    cout << x << " + (" << y << ")i";
}
#endif