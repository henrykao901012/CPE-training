#include <iostream>

using namespace std;

class point
{
public:
   double px, py;
};

class reg
{
public:
   point left, right;
};

int main()
{
   reg R[10];
   char getchar;
   int t = 0;
   while (cin >> getchar && getchar != '*')
   {
      cin >> R[t].left.px >> R[t].left.py >> R[t].right.px >> R[t].right.py;
      t++;
   }

   point p;
   int count = 0;
   bool in;
   while (cin >> p.px >> p.py)
   {
      if (p.px == 9999.9 && p.py == 9999.9)
         break;
      count++;
      in = false;
      for (int i = 0; i < t; i++)
      {
         if (p.px > R[i].left.px && p.px < R[i].right.px && p.py > R[i].right.py && p.py < R[i].left.py)
         {
            in = true;
            printf("Point %d is contained in figure %d\n", count, i + 1);
         }
      }
      if (!in)
         printf("Point %d is not contained in any figure\n", count);
   }

   system("pause");
   return 0;
}

/*
r 8.5 17.0 25.5 -8.5
r 0.0 10.3 5.5 0.0
r 2.5 12.5 12.5 2.5
*
2.0 2.0
4.7 5.3
6.9 11.2
20.0 20.0
17.6 3.2
-5.2 -7.8
9999.9 9999.9
*/