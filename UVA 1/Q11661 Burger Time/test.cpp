#include <iostream>

using namespace std;
int main()
{
   int n;
   while (cin >> n && n)
   {
      string str;
      cin >> str;

      int min_dis = n, lastR = -n, lastD = -n;
      for (int i = 0; i < n; i++)
      {
         if (str[i] == 'Z')
         {
            min_dis = 0;
            break;
         }
         else if (str[i] == 'R')
         {
            min_dis = min(min_dis, i - lastD);
            lastR = i;
         }
         else if (str[i] == 'D')
         {
            min_dis = min(min_dis, i - lastR);
            lastD = i;
         }
      }

      cout << min_dis << "\n";
   }

   system("pause");
   return 0;
}
