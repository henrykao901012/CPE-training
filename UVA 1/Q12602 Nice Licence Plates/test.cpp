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

      int ch = 676 * (str[0] - 'A') + 26 * (str[1] - 'A') + str[2] - 'A';
      int num = 1000 * (str[4] - '0') + 100 * (str[5] - '0') + 10 * (str[6] - '0') + str[7] - '0';

      string ans = abs(ch - num) <= 100 ? "nice" : "not nice";
      cout << ans << "\n";
   }

   system("pause");
   return 0;
}
