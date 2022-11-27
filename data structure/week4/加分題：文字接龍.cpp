#include <algorithm>
#include <iostream>

using namespace std;
int main()
{
   int n;
   cin >> n;
   while (n--)
   {
      string str;
      cin >> str;

      for (int i = 0; i < str.length(); i++)
      {
         if (str[i] == 'a')
            reverse(str.begin() + i + 1, str.end());
         else if (str[i] == 'b')
            str += str.substr(i + 1);
         else if (str[i] == 'c')
         {
            if (i == str.length() - 2)
               str.erase(str.begin() + i + 1);
            else if (i != str.length() - 1)
               str.erase(str.begin() + i + 1, str.begin() + i + 3);
         }
      }
      cout << str << "\n";
   }

   system("pause");
   return 0;
}
