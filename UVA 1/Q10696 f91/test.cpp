#include <iostream>

using namespace std;

int fun(int x)
{
   if (x > 100)
      return x - 10;
   return fun(fun(x + 11));
}
int main()
{
   int n;
   while (cin >> n && n)
   {
      printf("f91(%d) = %d\n", n, fun(n));
   }

   system("pause");
   return 0;
}
