#include <iostream>

using namespace std;
int main()
{
   int k;
   while (cin >> k && k)
   {
      pair<int, int> div, get;
      cin >> div.first >> div.second;
      while (k--)
      {
         cin >> get.first >> get.second;
         if (div.first == get.first || div.second == get.second)
            cout << "divisa\n";
         else
         {
            bool x_cmp = get.first > div.first, y_cmp = get.second > div.second;
            if (x_cmp && y_cmp)
               cout << "NE\n";
            if (!x_cmp && y_cmp)
               cout << "NO\n";
            if (x_cmp && !y_cmp)
               cout << "SE\n";
            if (!x_cmp && !y_cmp)
               cout << "SO\n";
         }
      }
   }

   system("pause");
   return 0;
}
