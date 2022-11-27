#include <iostream>

using namespace std;

int main()
{
   const int mod[] = {76, 16, 56, 96, 36};

   int n;
   cin >> n;
   while (n--)
   {
      string str;
      cin >> str;

      if (str == "0")
         cout << "1\n";
      else if (str == "1")
         cout << "66\n";
      else
      {
         int last = str[str.length() - 1] - '0';
         last < 5 ? cout << mod[last] << "\n" : cout << mod[last - 5] << "\n";
      }
   }

   system("pause");
   return 0;
}

/*

1 66  { 76 16 56 96 36 }


*/
