#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

class prims_graph
{
public:
    int max_node, mst_cost;
    vector<vector<pii>> graph_list; //<node, cost>
    vector<int> parent, key;
    prims_graph() : max_node(-1), mst_cost(0), graph_list(100), parent(100, -1), key(100, numeric_limits<int>::max()) {}

    void get_graph_data();
    void prims_MST(int = 0);
    void dfs_out(int = -1);
};

void prims_graph::get_graph_data()
{
    int a, b, c;
    while (cin >> a >> b >> c)
    {
        graph_list[a].push_back({c, b});
        graph_list[b].push_back({c, a});
        max_node = max(a, b) > max_node ? max(a, b) : max_node;
    }
}

void prims_graph::prims_MST(int start)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> added(100, 0);
    pq.push({0, start});
    key[start] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second, weight = pq.top().first;
        pq.pop();

        if (added[u])
            continue;
        added[u] = 1;

        for (auto i : graph_list[u])
        {
            int v = i.second, w = i.first;
            //cout << "v = " << v << " w = " << w << " key[v] = " << key[v] << "\n";
            if (!added[v] && key[v] > w)
            {
                key[v] = w;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }
    /*
    int mst_cost = 0;
    for (int i = 0; i <= max_node; i++)
    {
        printf("%d: <%d,%d> %d\n", i + 1, parent[i], i, key[i]);
        mst_cost += key[i];
    }
    cout << mst_cost << "\n";
    */
}

void prims_graph::dfs_out(int v)
{
    //static vector<int> found(100, 0);
    static int count = 1;
    for (int i = 0; i <= max_node; i++)
    {
        if (parent[i] == v) //&&!found[i]
        {
            if (v != -1)
                printf("%d: <%d,%d>\n", count++, v, i);
            //found[v] = 1;
            mst_cost += key[i];
            dfs_out(i);
        }
    }
}

int main()
{
    prims_graph gra;
    int start;
    cin >> start;
    gra.get_graph_data();
    gra.prims_MST(start);
    gra.dfs_out();
    cout << "\nThe cost of minimum spanning tree: " << gra.mst_cost << "\n";
    system("pause");
    return 0;
}

/*
4
0 1 28
0 5 10
1 2 16
1 6 14
2 3 12
3 4 22
3 6 18
4 5 25
4 6 24
*/