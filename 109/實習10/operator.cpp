#include "operator.h"
#include "add.h"
#include "constructor.h"
#include "overload_operator.h"
#include "tool.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    /*                                              */
    bigint x, y("-1234"), z("+00000987654321");
    x.printnum();
    cout << "\n";

    y.printnum();
    cout << "\n";

    z.printnum();
    cout << "\n";

    cout << x << ' ' << y << ' ' << z << endl;

    x = z = y;
    cout << x << ' ' << y << ' ' << z << endl;

    x = y = -123;
    z = 123;
    cout << x << ' ' << y << ' ' << z << endl;

    x = 123;
    y = -123;
    z = -99;
    x += z;
    y += z;
    cout << x << ' ' << y << ' ' << z << endl;

    x = 123;
    y = -123;
    z = 99;
    x += z;
    y += z;
    cout << x << ' ' << y << ' ' << z << endl;

    x = 99;
    y = ++x;
    z = x++;
    cout << x << ' ' << y << ' ' << z << endl; //101 100 100

    x = -100;
    y = ++x;
    z = x++;
    cout << x << ' ' << y << ' ' << z << endl; //-98 -99 -99

    system("pause");
    return 0;
}
