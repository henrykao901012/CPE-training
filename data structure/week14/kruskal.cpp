#include <bits/stdc++.h>

using namespace std;
vector<int> lead(100, -1);

class kruskal_graph
{
public:
    int a, b, weight;
    kruskal_graph() : a(0), b(0), weight(numeric_limits<int>::max()) {}

    static bool cmp(kruskal_graph, kruskal_graph);
    static int Find(int);
    static void Union(int, int);
};

bool kruskal_graph::cmp(kruskal_graph a, kruskal_graph b)
{
    return a.weight < b.weight;
}

int kruskal_graph::Find(int x)
{
    return lead[x] == -1 ? x : Find(lead[x]);
}

void kruskal_graph::Union(int a, int b)
{
    //cout << "a = " << a << " b = " << b << "\n";
    //printf("Find(a) = %d, Find(b) = %d\n", Find(a), Find(b));
    if (Find(a) == Find(b))
        throw "same grope union crash";
    lead[max(Find(a), Find(b))] = min(Find(a), Find(b)); //    確保不會同組互相聯集 程式出錯
}

int main()
{

    kruskal_graph gra[100];
    int n = 0;
    while (cin >> gra[n].a >> gra[n].b >> gra[n++].weight)
        continue;

    sort(gra, gra + 100, kruskal_graph::cmp);

    int sum = 0, count = 1;
    for (int i = 0; i < n; i++)
    {
        if (kruskal_graph::Find(gra[i].a) != kruskal_graph::Find(gra[i].b))
        {
            kruskal_graph::Union(gra[i].a, gra[i].b);
            printf("%d: <%d,%d>\n", count++, gra[i].a, gra[i].b);
            sum += gra[i].weight;
        }
    }

    cout << "\nThe cost of minimum spanning tree: " << sum << "\n";

    system("pause");
    return 0;
}