#include <iostream>

using namespace std;
int main()
{
   int n;
   cin >> n;
   cout << "Lumberjacks:\n";
   while (n--)
   {
      int a[10];
      for (int i = 0; i < 10; i++)
         cin >> a[i];

      bool bigger = 1, smaller = 1;
      for (int i = 0; i < 9; i++)
      {
         bigger *= a[i] < a[i + 1];
         smaller *= a[i] > a[i + 1];
      }

      printf("%s\n", bigger || smaller ? "Ordered" : "Unordered");
   }

   system("pause");
   return 0;
}
