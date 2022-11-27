#include <algorithm>
#include <iostream>

using namespace std;
int main()
{
   int n;
   cin >> n;
   while (n--)
   {
      int a[3];
      cin >> a[0] >> a[1] >> a[2];
      sort(a, a + 3);

      printf("%s\n", a[0] + a[1] > a[2] ? "OK" : "Wrong!!");
   }

   system("pause");
   return 0;
}
