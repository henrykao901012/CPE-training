#ifndef FUNCTION
#define FUNCTION

#include "Mystring.h"
#include <iostream>
#include <string.h>
using namespace std;
class MyString
{
private:
    char *_data;
    int _len;
    static int _total_MyString;

public:
    MyString();
    MyString(const char *s);
    MyString(const MyString &s);
    ~MyString();

    static int total_MyString()
    {
        return _total_MyString;
    };

    MyString &operator=(const MyString &rhs);

    MyString &operator+=(const MyString &rhs);

    inline char &operator[](const int pos) const; //

    unsigned length() const;

    friend ostream &operator<<(ostream &, const MyString &);
    friend istream &operator>>(istream &, MyString &);

    bool operator==(const MyString &);
    friend bool operator!=(const MyString &, const MyString &);
};

class MyString_Derived : public MyString
{
    using MyString::MyString;
};

MyString::MyString()
{
    _data = NULL;
    _len = 0;
    MyString::_total_MyString++;
}

MyString::MyString(const char *s)
{
    _len = strlen(s);
    _data = new char[_len + 1];
    strcpy(_data, s);
    MyString::_total_MyString++;
}

MyString::MyString(const MyString &s)
{
    _len = s._len;
    _data = new char[_len + 1];
    strcpy(_data, s._data);
    MyString::_total_MyString++;
}

MyString::~MyString()
{
    delete[] _data;
    MyString::_total_MyString--;
}

MyString &MyString::operator=(const MyString &rhs)
{
    if (_len < rhs._len)
    {
        delete[] _data;
        _data = new char[rhs._len + 1];
        strcpy(_data, rhs._data);
    }
    else
    {
        strcpy(_data, rhs._data);
    }
    _len = rhs._len;
    return *this;
}

MyString &MyString::operator+=(const MyString &rhs)
{
    int len1 = this->_len;
    int len2 = rhs._len;
    if (_len < len1 + len2 + 1)
    {
        char *tmp = new char[this->_len + 1];
        strcpy(tmp, this->_data);
        delete[] _data;
        _data = new char[len1 + len2 + 1 + 1];
        strcpy(this->_data, tmp);
        delete[] tmp;
    }
    strcat(_data, " ");
    strcat(_data, rhs._data);
    _len = strlen(_data);
    return *this;
}

inline char &MyString::operator[](const int pos) const
{
    return _data[pos];
}

unsigned MyString::length() const
{
    return _len;
}

ostream &operator<<(ostream &output, const MyString &tmp)
{
    for (int i = 0; i < tmp._len; i++)
    {
        cout << tmp[i];
    }
    return output;
}

istream &operator>>(istream &input, MyString &tmp)
{
    cin.clear();
    char a[50];
    input.getline(a, 50);
    ;
    if (tmp._len < strlen(a))
    {
        delete[] tmp._data;
        tmp._data = new char[strlen(a)];
    }
    strcpy(tmp._data, a);
    tmp._len = strlen(a);
    cin.clear();

    return input;
}

bool MyString::operator==(const MyString &tmp)
{
    if (!(strcmp(this->_data, tmp._data)))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool operator!=(const MyString &a, const MyString &b)
{
    if ((strcmp(a._data, b._data)))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
#endif