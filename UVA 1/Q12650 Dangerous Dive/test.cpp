#include <iostream>

using namespace std;
int main()
{
   int n, r;
   while (cin >> n >> r)
   {
      bool man[10000] = {0};
      for (int i = 0; i < r; i++)
      {
         int get;
         cin >> get;
         man[get - 1] = 1;
      }

      if (n == r)
      {
         cout << "*\n";
         continue;
      }

      for (int i = 0; i < n; i++)
         if (!man[i])
            cout << i + 1 << " ";
      cout << "\n";
   }

   system("pause");
   return 0;
}
