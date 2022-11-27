#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
   if (a.first == b.first)
      return a.second > b.second;
   return a.first < b.first;
}
int main()
{
   string str;
   bool sum = 0;
   while (getline(cin, str))
   {
      if (sum)
         cout << "\n";
      sum = 1;
      pair<int, int> fre[127];
      for (int i = 0; i < 127; i++)
         fre[i] = {0, i};
      for (auto i : str)
         fre[(int)i].first++;

      sort(fre, fre + 127, cmp);

      for (auto i : fre)
         if (i.first)
            cout << i.second << " " << i.first << "\n";
      //cout << "\n";
   }

   system("pause");
   return 0;
}
