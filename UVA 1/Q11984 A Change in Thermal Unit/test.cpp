#include <iostream>

using namespace std;
int main()
{
   int t, count = 1;
   cin >> t;
   while (t--)
   {
      int c, d;
      cin >> c >> d;

      printf("Case %d: %.2f\n", count++, c + (double)5 / 9 * d);
   }

   system("pause");
   return 0;
}
