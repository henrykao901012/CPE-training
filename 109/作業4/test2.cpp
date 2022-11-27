#include "add.h"
#include "bigint_end.h"
#include "constructor.h"
#include "divide.h"
#include "overloading.h"
#include "times.h"
#include "tool.h"
#include <iostream>
#include <string>
using namespace std;
int bigint::count = 0;
int main()
{
    bigcomplexnum x, y("+10", "+20"), z(2, 4);

    cout << "x y z values: " << x << "   " << y << "   " << z << "\n\n";

    x = y + z;
    cout << "x = y + z -> " << x << "   " << y << "   " << z << "\n\n";
    x += y;
    cout << "x += y ->   " << x << "   " << y << "   " << z << "\n\n";
    y += z;
    cout << "y += z ->  " << x << "   " << y << "   " << z << "\n\n";

    y.setvalue(10, 20);
    z.setvalue(4, 2);
    cout << "y.setvalue(10, 20),z.setvalue(4, 2)   -> x y z values: " << x << "   " << y << "   " << z << "\n\n";
    x = y - z;
    cout << "x = y - z ->  " << x << "   " << y << "   " << z << "\n\n";
    x -= y;
    cout << "x -= y ->  " << x << "   " << y << "   " << z << "\n\n";
    z -= y;
    cout << "z -= y ->  " << x << "   " << y << "   " << z << "\n\n";
    y.setvalue(2, 4);
    z.setvalue(10, 20);
    cout << "y.setvalue(2, 4),z.setvalue(10, 20)   -> x y z values: " << x << "   " << y << "   " << z << "\n\n";
    x = y * z;
    cout << "x = y * z ->  " << x << "   " << y << "   " << z << "\n\n";
    x *= y;
    cout << "x *= y ->  " << x << "   " << y << "   " << z << "\n\n";
    z *= y;
    cout << "z *= y ->  " << x << "   " << y << "   " << z << "\n\n";

    system("pause");
    return 0;
}
