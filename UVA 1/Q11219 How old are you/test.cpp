#include <iostream>

using namespace std;

class birth
{
public:
   int date, month, year;
};

int main()
{
   int n, count = 1;
   cin >> n;
   while (n--)
   {
      birth now, bir;
      scanf("%d/%d/%d", &now.date, &now.month, &now.year);
      scanf("%d/%d/%d", &bir.date, &bir.month, &bir.year);

      //int ans = now.date - bir.date + (now.month - bir.month) * 30 + (now.year - bir.year) * 365;
      //cout << ans << "\n";        粗略算法會有bug

      now.month -= (now.date - bir.date) < 0;
      now.year -= (now.month - bir.month) < 0;
      if (now.year - bir.year < 0)
         printf("Case #%d: Invalid birth date\n", count);
      else if (now.year - bir.year > 130)
         printf("Case #%d: Check birth date\n", count);
      else
         printf("Case #%d: %d\n", count, now.year - bir.year);
      count++;
   }

   system("pause");
   return 0;
}
