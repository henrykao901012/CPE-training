#include <iostream>

using namespace std;
int main()
{
   int n;
   cin >> n;
   while (n--)
   {
      int a, b;
      cin >> a >> b;
      (a - b >= 0) && !((a - b) % 2) ? cout << (a + b) / 2 << " " << (a - b) / 2 << "\n" : cout << "impossible\n";
   }

   system("pause");
   return 0;
}
