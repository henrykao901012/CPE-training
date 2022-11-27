#include <iostream>

using namespace std;
int main()
{
   int n;
   while (cin >> n && n)
   {
      cout << n * (n + 1) * (n * 2 + 1) / 6 << "\n";
   }

   system("pause");
   return 0;
}
