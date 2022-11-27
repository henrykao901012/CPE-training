#include <bits/stdc++.h>

using namespace std;

class chain
{
public:
   int num;
   chain *p;

   static int size(chain *);

   static void insert(chain *&, int, int);
   static void push_back(chain *&, int);

   inline static const string POS_ERROR = "Invalid position.";
};

int chain::size(chain *start)
{
   int count = 0;
   while (start)
   {
      start = start->p;
      count++;
   }
   return count;
}

void chain::insert(chain *&start, int pos, int n)
{
   if (pos < 0 || pos > size(start))
      throw POS_ERROR;
   if (!pos)
   {
      chain *created = new chain;
      created->num = n;
      created->p = start;
      start = created;
      return;
   }
   insert(start->p, pos - 1, n);
}

void chain::push_back(chain *&start, int n)
{
   insert(start, size(start), n);
}

class graph
{
public:
   vector<pair<chain *, int>> graph_list;
   vector<int> dfn, low;
   graph() : graph_list(100, {0, 0}), dfn(100, -1), low(100, -1) {}

   void insert(int, int, int = 1);
   void print();
   void dfs(int = 0);
   void bfs(int = 0);

   void dfnlow(int = 0, int = -1); // u -> start, v -> parent of u (if it had)
};

void graph::insert(int m, int n, int weight)
{
   if (m < 0 || n < 0)
      throw "invald position";
   if (m == n)
      throw "recursive graph path";
   chain::push_back(graph_list[m].first, n);
   chain::push_back(graph_list[n].first, m);
   graph_list[m].second = graph_list[n].second = weight;
}

void graph::dfs(int v)
{
   if (v < 0)
      throw "position invalid";

   static vector<int> found(100, 0);
   found[v] = 1;
   cout << v << " ";
   for (auto i = graph_list[v].first; i; i = i->p)
      if (!found[i->num])
         dfs(i->num);
}

void graph::bfs(int v)
{
   if (v < 0)
      throw "position invalid";

   vector<int> found(100, 0);
   queue<int> que;

   que.push(v);
   found[v] = 1;
   while (!que.empty())
   {
      int get = que.front();
      que.pop();
      cout << get << " ";
      //s += to_string(get) + " ";
      for (auto i = graph_list[get].first; i; i = i->p)
      {
         if (!found[i->num])
         {
            que.push(i->num);
            found[i->num] = 1;
         }
      }
   }
}

void graph::dfnlow(int u, int v)
{
   static int count = 0;
   dfn[u] = low[u] = count++;
   //cout << "u = " << u << " v = " << v << "\n";
   for (auto i = graph_list[u].first; i; i = i->p)
   {
      if (dfn[i->num] < 0)
      {
         //cout << "here  i->num = " << i->num << "\n";
         dfnlow(i->num, u);
         low[u] = low[u] < low[i->num] ? low[u] : low[i->num];
      }
      else if (i->num != v)
         low[u] = low[u] < dfn[i->num] ? low[u] : dfn[i->num];
   }
}

void graph::print()
{
   for (int i = 0; i < graph_list.size(); i++)
   {
      cout << i << " -> ";
      for (auto j = graph_list[i].first; j; j = j->p)
         cout << j->num << " ";
      cout << "\n";
   }
}

int main()
{
   graph gra;
   int a, b, max = -1;
   while (cin >> a >> b)
   {
      gra.insert(a, b);
      max = (a > b ? a : b) > max ? (a > b ? a : b) : max;
   }

   //gra.print();

   gra.dfnlow(3);

   cout << "    ";
   for (int i = 0; i <= max; i++)
      cout << i << " \n"[i == max];

   cout << "dfn ";
   for (int i = 0; i <= max; i++)
      cout << gra.dfn[i] << " \n"[i == max];

   cout << "low ";
   for (int i = 0; i <= max; i++)
      cout << gra.low[i] << " \n"[i == max];

   system("pause");
   return 0;
}