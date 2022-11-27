#include <iostream>

using namespace std;

string getstr_dig(string str)
{
   return to_string(str.length());
}

int main()
{
   string str;
   while (cin >> str && str != "END")
   {
      if (str == "1")
      {
         cout << "1\n";
         continue;
      }

      int count = 1;
      while (getstr_dig(str) != "1")
      {
         str = getstr_dig(str);
         count++;
      }
      cout << ++count << "\n";
   }

   system("pause");
   return 0;
}
