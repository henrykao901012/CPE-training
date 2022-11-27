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

      if (str.length() == 5)
         cout << "3\n";
      else
      {
         string str_1 = "one";
         int wrong = 0;
         for (int i = 0; i < 3; i++)
            wrong += str[i] != str_1[i];

         wrong == 0 || wrong == 1 ? cout << "1\n" : cout << "2\n";
      }
   }

   system("pause");
   return 0;
}
