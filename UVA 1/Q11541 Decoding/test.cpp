#include <iostream>

using namespace std;
int main()
{
   int n, sum = 1;
   cin >> n;
   getchar();

   while (n--)
   {
      printf("Case %d: ", sum++);

      while (1)
      {
         char ch = getchar();
         if (ch == '\n')
            break;
         int num;
         cin >> num;

         for (int i = 0; i < num; i++)
            cout << ch;
      }
      cout << "\n";
   }

   system("pause");
   return 0;
}
