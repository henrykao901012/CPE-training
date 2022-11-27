#include <iostream>

using namespace std;
int main()
{
   int count;
   cin >> count;
   while (count--)
   {
      int n, m, data[100] = {0}, get, ans = 1;
      cin >> n >> m;

      for (int i = 0; i < m; i++)
         for (int j = 0; j < n; j++)
         {
            cin >> get;
            data[j] += get == 1;
         }

      for (int i = 0; i < n; i++)
      {
         //cout << data[i] << " ";
         if (data[i] > 1)
            ans *= data[i];
      }
      cout << ans << "\n";
   }

   system("pause");
   return 0;
}
