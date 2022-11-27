#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
   int n;
   cin >> n;
   getchar();
   while (n--)
   {
      string str;
      getline(cin, str);

      pair<int, int> num[100];
      for (int i = 0; i < 26; i++)
         num[i] = {i, 0};

      int max = 0;
      for (auto i : str)
         if (isalpha(i))
         {
            int get = islower(i) ? i - 'a' : tolower(i) - 'a';
            num[get].second++;
            if (num[get].second > max)
               max = num[get].second;
         }

      for (int i = 0; i < 100; i++)
         if (num[i].second == max)
            cout << (char)(num[i].first + 'a');
      cout << "\n";
   }

   system("pause");
   return 0;
}
