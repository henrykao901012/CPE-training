#include <cmath>
#include <iostream>

using namespace std;
int main()
{
   int x1, y1, x2, y2;
   while (cin >> x1 >> y1 >> x2 >> y2)
   {
      if (x1 + y1 + x2 + y2 == 0)
         break;
      if (x1 == x2 && y1 == y2)
         cout << "0\n";
      else if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2))
         cout << "1\n";
      else
         cout << "2\n";
   }

   system("pause");
   return 0;
}
