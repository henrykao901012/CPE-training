#include <iostream>

using namespace std;

int dpa(int a)
{
   int sum = 0;
   for (int i = 1; i < a; i++)
      sum += i * (a % i == 0);
   return sum;
}
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;

      if (n > dpa(n))
         cout << "deficient\n";
      else
         n == dpa(n) ? cout << "perfect\n" : cout << "abundant\n";
   }

   system("pause");
   return 0;
}
