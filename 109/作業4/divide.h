#ifndef DIVIDE_H
#define DIVIDE_H

#include "add.h"
#include "bigint_end.h"
#include "constructor.h"
#include "overloading.h"
#include "times.h"
#include "tool.h"
#include <iostream>
#include <string>
using namespace std;
void bigint::divide(int value)
{
    bigint t(value);
    divide(t);
}
void bigint::divide(string s)
{
    bigint t(s);
    divide(t);
}
void bigint::divide(bigint &x)
{
    bigint m = *this, n = x;
    m.sign = 1;
    n.sign = 1;
    for (int i = x.digits; i < m.digits; i++)
        n *= 10;
    int get[100] = {0}, temp = 0;
    while (m.digits >= x.digits && n.digits >= x.digits)
    {
        while (m.sign == 1)
        {
            m -= n;
            get[temp]++;
            //cout << "get[ " << temp << " ] = " << get[temp] << " m = " << m << " n = " << n << "\n";
        }
        m += n;
        get[temp]--;
        n.digits--;
        //cout << "get[ " << temp << " ] = " << get[temp] << " m = " << m << "\n";
        temp++;
    }
    //cout << "temp = " << temp << "\n";
    for (int i = 0; i < temp; i++)
        array_pointer[i] = get[i];
    int sum = 0;
    for (int i = 0; i < temp; i++)
        if (array_pointer[i] != 0)
            break;
        else
            sum++;
    for (int i = 0; i < temp; i++)
        array_pointer[i] = array_pointer[i + sum];
    for (int i = temp; i < size; i++)
        array_pointer[i] = 0;       
    digits = temp - sum;
    sign *= x.sign;
}

/*
void bigint::divide(bigint &x)
{
    bigint m = *this, n, t = x, temp = 1; ///////////// m -> 一直被減的除式，n -> 接收計數商，t -> 除式的倍數 ，temp -> 開始與現在的位數差
    t *= x.sign;
    m.sign = 1;
    for (int i = x.digits; i < m.digits; i++)
        t *= 10;
    int sum, utisum = 0;
   // bool exception = false;
    while (m.digits != 0 && utisum < digits)
    {
        sum = 0;
        while (m.sign == 1)
        {
            m -= t;
            n += temp;
            sum++;

            cout << "m = " << m << " t = " << t << " n = " << n << " temp = " << temp << " sum = " << sum << "\n";
        }
        m += t;
        n -= temp;

       
        if (t.digits > x.digits)
           t.digits--;
           
        if (sum != 1)
            temp *= 10;
        utisum++;
        cout << "m = " << m << " n = " << n << "\n";
    }

    n.reverse();
    n.sign = sign * x.sign;
    *this = n;
}
*/

#endif