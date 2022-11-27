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

    bigint x, y;

    x = 8;
    y = "+987654321098765432109876543210987654321098765432109876543210";
    y /= x;
    cout << "y / x = " << y;

    system("pause");
    return 0;
}
//////          1234/123            123/10