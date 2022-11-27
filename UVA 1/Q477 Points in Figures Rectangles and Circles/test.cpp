#include <iostream>

using namespace std;

class point
{
public:
   double px, py;
};

class gra
{
public:
   bool Isreg;
   point left, right;
   point heart;
   double rad;
};
double dis_squar(point a, point b)
{
   return (a.px - b.px) * (a.px - b.px) + (a.py - b.py) * (a.py - b.py);
}

int main()
{
   gra gra[10];
   char c;
   int t = 0;

   while (cin >> c && c != '*')
   {
      if (c == 'r')
      {
         gra[t].Isreg = true;
         cin >> gra[t].left.px >> gra[t].left.py >> gra[t].right.px >> gra[t].right.py;
      }
      else
      {
         gra[t].Isreg = false;
         cin >> gra[t].heart.px >> gra[t].heart.py >> gra[t].rad;
      }
      t++;
   }

   point p;
   bool in;
   int count = 0;
   while (cin >> p.px >> p.py)
   {
      if (p.px == 9999.9 && p.py == 9999.9)
         break;
      count++;
      in = false;
      for (int i = 0; i < t; i++)
      {
         if (gra[i].Isreg)
         {
            if (p.px > gra[i].left.px && p.px < gra[i].right.px && p.py > gra[i].right.py && p.py < gra[i].left.py)
            {
               in = true;
               printf("Point %d is contained in figure %d\n", count, i + 1);
            }
         }
         else
         {
            if (dis_squar(gra[i].heart, p) < gra[i].rad * gra[i].rad)
            {
               in = true;
               printf("Point %d is contained in figure %d\n", count, i + 1);
            }
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
c 20.2 7.3 5.8
r 0.0 10.3 5.5 0.0
c -5.0 -5.0 3.7
r 2.5 12.5 12.5 2.5
c 5.0 15.0 7.2
*
2.0 2.0
4.7 5.3
6.9 11.2
20.0 20.0
17.6 3.2
-5.2 -7.8
9999.9 9999.9
*/