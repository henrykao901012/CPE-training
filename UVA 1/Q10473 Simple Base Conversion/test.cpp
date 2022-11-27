#include <iostream>

using namespace std;
int main()
{
   string str;
   while (cin >> str)
   {
      if (str[0] == '-')
         break;

      if (str[0] != '0')
         printf("0x%X\n", stoi(str)); //%x 無號
      else
      {
         int num;
         sscanf(str.c_str(), "%x", &num);
         printf("%d\n", num);
      }
   }

   system("pause");
   return 0;
}
