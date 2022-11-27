#include <iostream>

using namespace std;
int main()
{
   int t, count = 1;
   cin >> t;
   while (t--)
   {
      string str;
      int len;
      cin >> len >> str;

      int sum = 0;
      for (int i = 0; i < len; i++)
      {
         if (str[i] == '.')
         {
            sum++;
            if (i + 1 < len)
               str[i + 1] = '#';
            if (i + 2 < len)
               str[i + 2] = '#';
         }
      }

      printf("Case %d: %d\n", count++, sum);
   }

   system("pause");
   return 0;
}
