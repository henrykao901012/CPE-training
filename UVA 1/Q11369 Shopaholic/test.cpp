#include <algorithm>
#include <iostream>

using namespace std;
bool cmp(int a, int b)
{
   return a > b;
}
int main()
{
   int n;
   cin >> n;
   while (n--)
   {
      int count, data[100000];
      cin >> count;
      for (int i = 0; i < count; i++)
         cin >> data[i];
      sort(data, data + count, cmp);

      int sum = 0;
      for (int i = 2; i < count; i += 3)
         sum += data[i];
      cout << sum << "\n";
   }

   system("pause");
   return 0;
}
