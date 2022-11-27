#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <string>
using namespace std;
class bigint
{
public:
    bigint();
    bigint(int value, int get = 100);
    bigint(string s, int get = 100);
    bigint(bigint &);
    ~bigint();
    void zero();
    void reverse();
    void carry();
    void printnum();
    void add(int value);
    void add(string s);
    void add(bigint &);

private:
    int *array_pointer;
    int size;
    int digits;
};

#endif