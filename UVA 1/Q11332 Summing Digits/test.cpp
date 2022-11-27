#include <iostream>

using namespace std;

int fun(int x)
{
   string str = to_string(x);
   int sum = 0;
   for (auto i : str)
      sum += i - '0';
   return sum < 10 ? sum : fun(sum);
}
int main()
{
   int n;
   while (cin >> n && n)
   {
      cout << fun(n) << "\n";
   }

   system("pause");
   return 0;
}
