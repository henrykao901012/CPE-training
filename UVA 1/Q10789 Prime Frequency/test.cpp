#include <iostream>

using namespace std;
bool isprime(int a)
{
   bool prime = (a != 1);
   for (int i = 2; i < a; i++)
      prime *= (a % i != 0);
   return prime;
}
int main()
{
   int n;
   cin >> n;

   for (int j = 1; j <= n; j++)
   {
      string str;
      cin >> str;

      printf("Case %d: ", j);

      int data[128] = {0};
      for (auto i : str)
         data[(int)i]++;

      bool out = 0;
      for (int i = 0; i < 128; i++)
      {
         //cout << i << " " << data[i] << "\n";
         if (isprime(data[i]) && data[i])
         {
            cout << (char)i;
            out = 1;
         }
      }
      if (out)
         cout << "\n";
      else
         cout << "empty\n";
   }

   system("pause");
   return 0;
}
