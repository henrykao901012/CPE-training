#include "bigint.h"
#include "function.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
   bigint x, y("1234"), z("000009876054321");

   cout << "x = ";
   x.printnum();

   cout << "y = ";
   y.printnum();

   cout << "z = ";
   z.printnum();

   y.add(z);
   cout << "y + z = ";
   y.printnum();

   bigint i(444, 2);
   cout << "i = ";
   i.printnum();

   bigint j(i);
   cout << "j = ";
   j.printnum();

   i.add(78);
   cout << "i + 78 = ";
   i.printnum();

   i.add("98765");
   cout << "i + 98765 = ";
   i.printnum();

   i.add(j);
   cout << "i + j = ";
   i.printnum();

   /*            */
   system("pause");
   return 0;
}
