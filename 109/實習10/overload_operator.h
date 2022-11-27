#ifndef OVERLOAD_OPERATOR_H
#define OVERLOAD_OPERATOR_H

#include "add.h"
#include "constructor.h"
#include "operator.h"
#include "tool.h"
#include <iostream>
using namespace std;

bigint &bigint ::operator=(int value)
{
    zero();
    add(value);
    return *this;
}
bigint &bigint::operator=(bigint &t)
{
    zero();
    add(t);
    return *this;
}
bigint &bigint::operator+=(bigint &t)
{
    add(t);
    return *this;
}
bigint &bigint::operator+=(int value)
{
    add(value);
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

#endif