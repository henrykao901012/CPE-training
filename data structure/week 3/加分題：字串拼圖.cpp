#include <iostream>
#include <vector>

using namespace std;

string reverse(string str)
{
   for (int i = 0; i < str.length() / 2; i++)
   {
      char t = str[i];
      str[i] = str[str.length() - 1 - i];
      str[str.length() - 1 - i] = t;
   }
   return str;
}
int main()
{
   int a, b;
   string pic[100];
   cin >> a >> b;
   for (int i = 0; i < a; i++)
      cin >> pic[i];

   vector<string> dic;
   for (int i = 0; i < a; i++)
      dic.push_back(pic[i] + pic[i]);
   for (int i = 0; i < a; i++)
   {
      string get;
      for (int j = 0; j < a; j++)
         get += pic[j][i];
      dic.push_back(get + get);
   }
   /*
        for (auto i : dic)
            cout << i << "\n";

    */
   const string ans[] = {"No", "Yes"};
   while (b--)
   {
      string str;
      cin >> str;

      bool get = 0;
      for (int i = 0; i < dic.size(); i++)
         get |= (dic[i].find(str) != string::npos || dic[i].find(reverse(str)) != string::npos);

      cout << ans[get] << "\n";
   }
   system("pause");
   return 0;
}
