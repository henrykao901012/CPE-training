#include <iostream>

using namespace std;
int main()
{
   int music[100];
   music[(int)'W'] = 64;
   music[(int)'H'] = 32;
   music[(int)'Q'] = 16;
   music[(int)'E'] = 8;
   music[(int)'S'] = 4;
   music[(int)'T'] = 2;
   music[(int)'X'] = 1;

   string str;
   while (cin >> str && str != "*")
   {
      int ans = 0, sum = 0;
      for (auto i : str)
      {
         if (i == '/')
         {
            ans += sum == 64;
            sum = 0;
         }
         else
            sum += music[(int)i];
      }

      cout << ans << "\n";
   }

   system("pause");
   return 0;
}
