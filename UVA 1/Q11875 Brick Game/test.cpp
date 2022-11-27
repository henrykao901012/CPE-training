#include <iostream>

using namespace std;
int main()
{
   int t, count = 1;
   cin >> t;
   while (t--)
   {
      int n, a[100];
      cin >> n;
      for (int i = 0; i < n; i++)
         cin >> a[i];

      printf("Case %d: %d\n", count++, a[n / 2]);
   }

   system("pause");
   return 0;
}
