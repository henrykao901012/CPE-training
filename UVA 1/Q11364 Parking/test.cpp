#include <iostream>

using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n, shop[100];
      cin >> n;

      int min = 100, max = -1;
      for (int i = 0; i < n; i++)
      {
         cin >> shop[i];
         if (shop[i] < min)
            min = shop[i];
         if (shop[i] > max)
            max = shop[i];
      }
      cout << (max - min) * 2 << "\n";
   }

   system("pause");
   return 0;
}
