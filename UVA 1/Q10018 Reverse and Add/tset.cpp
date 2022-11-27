#include <iostream>
#include <string>
using namespace std;
string reverse(string str)
{
   for (int i = 0; i < str.length() / 2; i++)
   {
      char t = str[i];
      str[i] = str[str.length() - i - 1];
      str[str.length() - i - 1] = t;
   }
   return str;
}
int main()
{
   int n;
   cin >> n;

   while (n)
   {
      long long num;
      cin >> num;
      int count = 0;
      do
      {
         num += stoll(reverse(to_string(num)));
         count++;
      } while (num != stoll(reverse(to_string(num))));

      cout << count << " " << num << "\n";
      n--;
   }

   system("pause");
   return 0;
}
