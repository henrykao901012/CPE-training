#include <iostream>

using namespace std;
int main()
{

   int n;
   while (cin >> n)
   {
      long long int sum = 1;
      for (int i = 3; i <= n; i += 2)
         sum += i * 2;
      cout << sum * 3 - 6 << "\n";
   }

   system("pause");
   return 0;
}
/*
   3
   5
   7
*/