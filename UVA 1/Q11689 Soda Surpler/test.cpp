#include <iostream>

using namespace std;
int main()
{
   int n;
   cin >> n;
   while (n--)
   {
      int e, f, c;
      cin >> e >> f >> c;

      e += f;
      int sum = 0;
      while (e >= c)
      {
         sum += e / c;
         e = e % c + e / c;
      }
      cout << sum << "\n";
   }

   system("pause");
   return 0;
}
