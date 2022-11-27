#include <bits/stdc++.h>

using namespace std;
string s;

class chain
{
public:
    int num;
    chain *p;

    static void insert(chain *&, int, int);
    static int at(chain *, int);

    static void print(chain *);
    static int size(chain *);
    inline static const string POS_ERROR = "Invalid position.";
};

void chain::print(chain *start)
{
    //cout << "Created Linked list is:";
    stringstream ans;
    while (start)
    {
        ans << start->num << " ";
        start = start->p;
    }
    cout << ans.str().substr(0, ans.str().size() - 1) << "\n";
}

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

int chain::at(chain *start, int pos)
{
    if (pos < 0 || pos >= size(start))
        throw POS_ERROR;
    while (pos--)
        start = start->p;
    return start->num;
}

class graph
{
public:
    chain *graph_list[100];
    graph() : graph_list({0}) {}

    void insert(int, int);
    void dfs(int = 1);
    void bfs(int = 1);
};

void graph::insert(int m, int n)
{
    if (m == n)
        throw "recursive road";
    chain::insert(graph_list[m], chain::size(graph_list[m]), n);
    chain::insert(graph_list[n], chain::size(graph_list[n]), m);
}

void graph::dfs(int v)
{
    if (v < 0)
        throw "position invalid";

    static vector<int> found(100, 0);
    found[v] = 1;
    s += to_string(v) + " ";
    for (auto i = graph_list[v]; i; i = i->p)
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
        s += to_string(get) + " ";
        for (auto i = graph_list[get]; i; i = i->p)
        {
            if (!found[i->num])
            {
                que.push(i->num);
                found[i->num] = 1;
            }
        }
    }
}

int main()
{
    graph gra;
    int m, n;
    while (cin >> m >> n)
    {
        gra.insert(m, n);
    }

    /*
    for (int i = 0; i < 4; i++)
    {
        cout << i << " -> ";
        chain_lib.print(graph_list[i]);
    }
    */

    cout << "Depth First Search:\n";
    gra.dfs();
    cout << s.substr(0, s.size() - 1) << "\n";
    s.clear();

    cout << "\nBreadth First Search:\n";
    gra.bfs();
    cout << s.substr(0, s.size() - 1) << "\n";

    system("pause");
    return 0;
}
/*
0 1
0 2
1 3
1 4
2 5
2 6
3 7
4 7
5 7
6 7
*/