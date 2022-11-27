#include <iostream>
#include <math.h>
using namespace std;
int main()
{
   int n;
   while (cin >> n)
   {
      int num[3000];
      for (int i = 0; i < n; i++)
         cin >> num[i];

      bool jump[3000] = {0}, isjolly = true;
      for (int i = 0; i < n - 1; i++)
      {
         if (abs(num[i] - num[i + 1]) == 0 || abs(num[i] - num[i + 1]) > n - 1)
         {
            isjolly = false;
            break;
         }
         jump[abs(num[i] - num[i + 1])] = true;
      }
      for (int i = 1; i <= n - 1; i++)
      {
         //cout << jump[i] << " ";
         isjolly *= jump[i];
      }

      if (isjolly)
         cout << "Jolly\n";
      else
         cout << "Not jolly\n";
   }

   system("pause");
   return 0;
}
