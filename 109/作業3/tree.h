#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <string.h>
#include <string>
#include <time.h>

using namespace std;

template <class T>
struct treeNodeTP
{
    treeNodeTP<T> *leftPtr;
    T data;
    treeNodeTP<T> *rightPtr;
};

int compareFun(int a, int b)
{
    if (a == b)
        return 0;
    return a > b ? 1 : -1;
}
int compareFun(float a, float b)
{
    if (a == b)
        return 0;
    return a > b ? 1 : -1;
}

void printFun(int a)
{
    cout << a << " ";
}
void printFun(float a)
{
    cout << a << " ";
}

template <class T>
void preOrderTP(treeNodeTP<T> *treePtr)
{
    if (treePtr != NULL)
    {
        printFun(treePtr->data);
        preOrderTP(treePtr->leftPtr);
        preOrderTP(treePtr->rightPtr);
    }
}

template <class T>
void inOrderTP(treeNodeTP<T> *treePtr)
{
    if (treePtr != NULL)
    {
        inOrderTP(treePtr->leftPtr);
        printFun(treePtr->data);
        inOrderTP(treePtr->rightPtr);
    }
}

template <class T>
void postOrderTP(treeNodeTP<T> *treePtr)
{
    if (treePtr != NULL)
    {
        postOrderTP(treePtr->leftPtr);
        postOrderTP(treePtr->rightPtr);
        printFun(treePtr->data);
    }
}

template <class T>
void insertNodeTP(treeNodeTP<T> *&rootPtr, T value)
{
    if (rootPtr == NULL)
    {
        rootPtr = new treeNodeTP<T>;
        rootPtr->data = value;
        rootPtr->leftPtr = rootPtr->rightPtr = NULL;
        return;
    }
    if ((compareFun(rootPtr->data, value)) == 0)
    {
        return;
    }
    else if ((compareFun(rootPtr->data, value)) > 0)
    {
        insertNodeTP(rootPtr->leftPtr, value);
    }
    else if ((compareFun(rootPtr->data, value)) < 0)
    {
        insertNodeTP(rootPtr->rightPtr, value);
    }
}

///////////////////////////////////////////////////////////////////////
struct book
{
    string bookName; //書名當成 key 來比較大小
    string authors;
    int price;
};

int compareFun(book a, book b)
{
    /*  if (a.bookName.length() == b.bookName.length())
        return 0;
    return a.bookName.length() > b.bookName.length() ? 1 : -1;      */

    /*string t1 = a.bookName;
    string t2 = b.bookName;
    const char *p1 = t1.c_str();
    const char *p2 = t2.c_str();
    return strcmp(p1, p2);      */

    return a.bookName.compare(b.bookName);
}

void printFun(book a)
{
    cout << "\" " << a.bookName << " \"   \" " << a.authors << " \"   " << a.price << "\n";

}

void setBookData(book &item, string bookName, string authors, int price)
{
    item.bookName = bookName;
    item.authors = authors;
    item.price = price;
}

#endif