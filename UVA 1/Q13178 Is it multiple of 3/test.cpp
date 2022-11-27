#include <iostream>

using namespace std;

int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      long long n;
      cin >> n;

      //cout << n * (n + 1) << "\n";
      n *(n + 1) % 3 == 0 ? cout << "YES\n" : cout << "NO\n";
   }

   system("pause");
   return 0;
}
