#include <cmath>
#include <iostream>

using namespace std;
int main()
{
   int n;
   cin >> n;
   bool enter = 0;
   while (n--)
   {
      if (enter)
         cout << "\n";
      enter = 1;

      int w;
      cin >> w;

      int x, y;
      cin >> x >> y;
      int count = abs(x - y);

      bool con = 1;
      for (int i = 1; i < w; i++)
      {
         cin >> x >> y;
         con *= count == abs(x - y);
      }

      if (con)
         cout << "yes\n";
      else
         cout << "no\n";
   }

   system("pause");
   return 0;
}
