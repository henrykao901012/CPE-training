#include <iostream>

using namespace std;
int main()
{
   int t, count = 1;
   cin >> t;
   while (t--)
   {
      int n, wall[100];
      cin >> n;
      for (int i = 0; i < n; i++)
         cin >> wall[i];

      int hj = 0, lj = 0;
      for (int i = 0; i < n - 1; i++)
      {
         hj += wall[i] < wall[i + 1];
         lj += wall[i] > wall[i + 1];
      }

      printf("Case %d: %d %d\n", count++, hj, lj);
   }

   system("pause");
   return 0;
}
