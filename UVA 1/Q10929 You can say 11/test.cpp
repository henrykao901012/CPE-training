#include <iostream>

using namespace std;
int main()
{
   string str;
   while (cin >> str && str != "0")
   {
      int sum_odd = 0, sum_even = 0;
      for (int i = 0; i < str.length(); i++)
      {
         if (i % 2)
            sum_even += str[i] - '0';
         else
            sum_odd += str[i] - '0';
      }
      //cout << sum_odd << "  " << sum_even << "  " << abs(sum_odd - sum_even) % 11 << "  ";
      if (sum_odd - sum_even == (sum_odd - sum_even) / 11 * 11)
         cout << str << " is a multiple of 11.\n";
      else
         cout << str << " is not a multiple of 11.\n";
   }

   system("pause");
   return 0;
}
