#ifndef OVERLOAD_OPERATOR_H
#define OVERLOAD_OPERATOR_H

#include "add.h"
#include "bigint_end.h"
#include "constructor.h"
#include "times.h"
#include "tool.h"
#include <iostream>
using namespace std;

bigint &bigint ::operator=(int value)
{
    zero();
    add(value);
    return *this;
}
bigint &bigint ::operator=(string s)
{
    zero();
    add(s);
    return *this;
}
bigint &bigint::operator=(bigint &t)
{
    zero();
    add(t);
    return *this;
}
bigint &bigint::operator+(int value)
{
    bigint *m = new bigint(*this);
    *m += value;
    return *m;
}
bigint &bigint::operator+(string s)
{
    bigint *m = new bigint(*this);
    *m += s;
    return *m;
}
bigint &bigint::operator+(bigint &t)
{
    bigint *m = new bigint(*this);
    *m += t;
    return *m;
}
bigint &bigint::operator-(int value)
{
    bigint *m = new bigint(*this);
    *m -= value;
    return *m;
}
bigint &bigint::operator-(string s)
{
    bigint *m = new bigint(*this);
    *m -= s;
    return *m;
}
bigint &bigint::operator-(bigint &t)
{
    bigint *m = new bigint(*this);
    *m -= t;
    return *m;
}
bigint &bigint::operator*(int value)
{
    bigint *m = new bigint(*this);
    *m *= value;
    return *m;
}
bigint &bigint::operator*(string s)
{
    bigint *m = new bigint(*this);
    *m *= s;
    return *m;
}
bigint &bigint::operator*(bigint &t)
{
    bigint *m = new bigint(*this);
    *m *= t;
    return *m;
}
bigint &bigint::operator/(int value)
{
    bigint *m = new bigint(*this);
    *m /= value;
    return *m;
}
bigint &bigint::operator/(string s)
{
    bigint *m = new bigint(*this);
    *m /= s;
    return *m;
}
bigint &bigint::operator/(bigint &t)
{
    bigint *m = new bigint(*this);
    *m /= t;
    return *m;
}

bigint &bigint::operator+=(int value)
{
    add(value);
    return *this;
}
bigint &bigint::operator+=(string s)
{
    add(s);
    return *this;
}
bigint &bigint::operator+=(bigint &t)
{
    add(t);
    return *this;
}
bigint &bigint::operator++() ////////////////   ++i
{
    add(1);
    return *this;
}
bigint &bigint::operator++(int) /////////////////  i++
{
    bigint *t = new bigint(*this);
    add(1);
    return *t;
}
bigint &bigint::operator-=(int value)
{
    bigint t(value);
    t.sign *= -1;
    add(t);
    t.sign *= -1;
    return *this;
}
bigint &bigint::operator-=(string s)
{
    bigint t(s);
    t.sign *= -1;
    add(t);
    t.sign *= -1;
    return *this;
}
bigint &bigint::operator-=(bigint &t)
{
    t.sign *= -1;
    add(t);
    t.sign *= -1;
    return *this;
}
bigint &bigint::operator--() ////////////////   ++i
{
    add(-1);
    return *this;
}
bigint &bigint::operator--(int) /////////////////  i++
{
    bigint *t = new bigint(*this);
    add(-1);
    return *t;
}
bigint &bigint::operator*=(int value)
{
    times(value);
    return *this;
}
bigint &bigint::operator*=(string s)
{
    times(s);
    return *this;
}
bigint &bigint::operator*=(bigint &t)
{
    times(t);
    return *this;
}
bigint &bigint::operator/=(int value)
{
    divide(value);
    return *this;
}
bigint &bigint::operator/=(string s)
{
    divide(s);
    return *this;
}
bigint &bigint::operator/=(bigint &t)
{
    divide(t);
    return *this;
}
////////////////////////////////////////////////////////
bigcomplexnum &bigcomplexnum::operator=(bigcomplexnum &t)
{
    setvalue(t.x, t.y);
    return *this;
}
bigcomplexnum &bigcomplexnum::operator+(bigcomplexnum &t)
{
    bigcomplexnum *m = new bigcomplexnum(*this);
    *m += t;
    return *m;
}
bigcomplexnum &bigcomplexnum::operator-(bigcomplexnum &t)
{
    bigcomplexnum *m = new bigcomplexnum(*this);
    *m -= t;
    return *m;
}
bigcomplexnum &bigcomplexnum::operator*(bigcomplexnum &t)
{
    bigcomplexnum *m = new bigcomplexnum(*this);
    *m *= t;
    return *m;
}
bigcomplexnum &bigcomplexnum::operator+=(bigcomplexnum &t)
{
    x.add(t.x);
    y.add(t.y);
    return *this;
}
bigcomplexnum &bigcomplexnum::operator-=(bigcomplexnum &t)
{
    x.add(t.x * -1);
    y.add(t.y * -1);
    return *this;
}
bigcomplexnum &bigcomplexnum::operator*=(bigcomplexnum &t)
{
    bigint m = x;
    x = x * t.x - y * t.y;
    y = m * t.y + y * t.x;
    return *this;
}

#endif