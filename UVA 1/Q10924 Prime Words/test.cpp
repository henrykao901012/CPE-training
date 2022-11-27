#include <iostream>

using namespace std;

bool isprime(int a)
{
   bool prime = 1;
   for (int i = 2; i < a; i++)
      prime *= (a % i != 0);
   return prime;
}
int main()
{
   string str;
   while (cin >> str)
   {
      int sum = 0;
      for (auto i : str)
      {
         if (islower(i))
            sum += i - 'a' + 1;
         else
            sum += i - 'A' + 27;
      }
      if (isprime(sum))
         cout << "It is a prime word.\n";
      else
         cout << "It is not a prime word.\n";
   }

   system("pause");
   return 0;
}
