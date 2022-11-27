#include <bitset>
#include <iostream>

using namespace std;
int main()
{
   string get_str, ans_str, flag = "1";
   while (cin >> get_str && get_str != "~")
   {
      if (get_str == "#")
      {
         bitset<100> bits(ans_str);
         cout << bits.to_ulong() << "\n";

         flag = "1", ans_str = "";
      }
      else if (get_str.length() == 1)
         flag = "1";
      else if (get_str.length() == 2)
         flag = "0";
      else
         for (int i = 0; i < get_str.length() - 2; i++)
            ans_str += flag;
   }

   system("pause");
   return 0;
}

// 這題真的?????????