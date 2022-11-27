#include <iostream>
#include <string>

using namespace std;

int main()
{
   int a, b;
   while (cin >> a >> b)
   {
      if (a + b == 0)
         break;
      int carry = 0, count = 0;
      while (a || b)
      {
         carry = a % 10 + b % 10 + carry > 9 ? 1 : 0;
         count += carry;
         a /= 10;
         b /= 10;
      }
      switch (count)
      {
      case 0:
         cout << "No carry operation.\n";
         break;
      case 1:
         cout << "1 carry operation.\n";
         break;
      default:
         cout << count << " carry operations.\n";
      }
   }

   system("pause");
   return 0;
}
