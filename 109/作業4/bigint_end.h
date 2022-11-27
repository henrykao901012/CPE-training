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
    static int getcount();

    void add(int);
    void add(string);
    void add(bigint &);

    void times(int);
    void times(string);
    void times(bigint &);

    void divide(int);
    void divide(string);
    void divide(bigint &);

    friend ostream &operator<<(ostream &, bigint &);

    bigint &operator=(int);
    bigint &operator=(string);
    bigint &operator=(bigint &);
    /* */
    bigint &operator+(int);
    bigint &operator+(string);
    bigint &operator+(bigint &);
    bigint &operator-(int);
    bigint &operator-(string);
    bigint &operator-(bigint &);
    /* */
    /* */
    bigint &operator*(int);
    bigint &operator*(string);
    bigint &operator*(bigint &);
    bigint &operator/(int);
    bigint &operator/(string);
    bigint &operator/(bigint &);
    /* */
    bigint &operator+=(int);
    bigint &operator+=(string);
    bigint &operator+=(bigint &);
    bigint &operator++();    ////// ++i
    bigint &operator++(int); /////  i++
    bigint &operator-=(int);
    bigint &operator-=(string);
    bigint &operator-=(bigint &);
    bigint &operator--();
    bigint &operator--(int);
    bigint &operator*=(int);
    bigint &operator*=(string);
    bigint &operator*=(bigint &);
    bigint &operator/=(int);
    bigint &operator/=(string);
    bigint &operator/=(bigint &);

private:
    int *array_pointer;
    int size;
    int digits;
    int sign;
    static int count;
};
ostream &operator<<(ostream &s, bigint &t)
{
    t.printnum();
    return s;
}
class bigcomplexnum
{
public:
    bigint x, y;

    bigcomplexnum();
    bigcomplexnum(int, int);
    bigcomplexnum(string, string);

    void setvalue(int, int);
    void setvalue(bigint &, bigint &);
    void printnum();

    friend ostream &operator<<(ostream &, bigcomplexnum &);

    bigcomplexnum &operator=(bigcomplexnum &);
    bigcomplexnum &operator+(bigcomplexnum &);
    bigcomplexnum &operator-(bigcomplexnum &);
    bigcomplexnum &operator*(bigcomplexnum &);
    bigcomplexnum &operator+=(bigcomplexnum &);
    bigcomplexnum &operator-=(bigcomplexnum &);
    bigcomplexnum &operator*=(bigcomplexnum &);
};
ostream &operator<<(ostream &s, bigcomplexnum &t)
{
    t.printnum();
    return s;
}
#endif