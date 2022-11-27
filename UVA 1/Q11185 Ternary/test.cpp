
#include <iostream>

using namespace std;

int main()
{
   int n;
   while (cin >> n && n >= 0)
   {
      int str[100];
      int count = 0;
      do
      {
         str[count] = n % 3;
         n /= 3;
         count++;
      } while (n);

      cout << str[--count];
      while (count--)
         cout << str[count];
      cout << "\n";
   }

   system("pause");
   return 0;
}
///////////////////    using itoa in <cstdlib>

/*
   itoa函式原型為char*iota(int value,char *string,int radix);
   value為被轉化的整數
   string為轉換後儲存的字元陣列，
   adix為要轉換的進位制數
*/

/*
      int n;
      while (cin >> n && n >= 0)
      {
         char str[100];
         itoa(n, str, 3);
         printf("%s\n", str);
      }
*/
// UVA不給過 垃圾
