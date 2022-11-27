#ifndef OPERATOR_H
#define OPERATOR_H

#include <iostream>
#include <string>
using namespace std;
class bigint
{
public:
    bigint();
    bigint(int, int = 100);
    bigint(string, int = 100);
    bigint(bigint &);
    ~bigint();

    void zero();
    void reverse();
    int countzero();
    int countzero(string);
    void carry();
    void printnum();

    void add(int);
    void add(string);
    void add(bigint &);

    friend ostream &operator<<(ostream &, bigint &);
    bigint &operator=(bigint &);
    bigint &operator=(int);
    bigint &operator+=(bigint &);
    bigint &operator+=(int);
    bigint &operator++();
    bigint &operator++(int);

private:
    int *array_pointer;
    int size;
    int digits;
    int sign;
};
ostream &operator<<(ostream &s, bigint &t)
{
    t.printnum();
    return s;
}
#endif