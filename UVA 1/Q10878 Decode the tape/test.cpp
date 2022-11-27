#include <iostream>

using namespace std;
int main()
{
   int c[] = {0, 0, 64, 32, 16, 8, 0, 4, 2, 1, 0};

   string str;
   getline(cin, str);

   while (getline(cin, str) && str[0] != '_')
   {
      int sum = 0;
      for (int i = 0; i < str.length(); i++)
         sum += c[i] * (str[i] == 'o');
      cout << (char)sum;
   }

   system("pause");
   return 0;
}
