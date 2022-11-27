#include <iostream>

using namespace std;

class mydata
{
public:
   int win = 0, lose = 0;
};

int main()
{
   int n;
   bool time = 0;
   while (cin >> n && n)
   {
      if (time)
         cout << "\n";
      time = 1;

      int k;
      cin >> k;
      mydata player[200];
      for (int i = 0; i < k * n * (n - 1) / 2; i++)
      {
         int x, y;
         string a, b;
         cin >> x >> a >> y >> b;
         bool win_a = 0, lose_a = 0, win_b = 0, lose_b = 0;
         if ((a == "paper" && b == "rock") || (a == "scissors" && b == "paper") || (a == "rock" && b == "scissors"))
            win_a = lose_b = 1;
         else if ((a == "rock" && b == "paper") || (a == "paper" && b == "scissors") || (a == "scissors" && b == "rock"))
            win_b = lose_a = 1;

         player[x - 1].win += win_a;
         player[x - 1].lose += lose_a;
         player[y - 1].win += win_b;
         player[y - 1].lose += lose_b;
      }
      for (int i = 0; i < n; i++)
      {
         if (player[i].win + player[i].lose)
            printf("%.3f\n", (double)player[i].win / (player[i].win + player[i].lose));
         else
            cout << "-\n";
      }
   }

   system("pause");
   return 0;
}

///////