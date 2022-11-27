#include <bits/stdc++.h>

using namespace std;
vector<int> a(100, -1);

int leader(int m)
{
    while (a[m] != -1)
        m = a[m];
    return m;
}

int Find(int x)
{
    if (a[x] == -1)
        return x;
    return a[x] = Find(a[x]);
}

void Union(int m, int n)
{
    /* int finda = Find(m), findb = Find(n);
    if (finda < findb)
        swap(finda, findb);
    cout << finda << " " << findb << "\n";

    a[finda] = findb;*/

    int get1 = Find(m) < Find(n) ? Find(n) : Find(m), get2 = Find(m) < Find(n) ? Find(m) : Find(n);
    a[get1] = get2;
    //cout << get1 << " " << get2 << "\n";
}

void Print_Union(int m, int n, int count)
{
    printf("Union(%d,%d):", m, n);

    for (int i = 0; i < count; i++)
        if (a[i] != -1)
            a[i] = leader(i);

    for (int i = 0; i < count; i++)
    {
        if (a[i] == -1)
        {
            cout << " {" << i;
            for (int j = 0; j < count; j++)
            {
                if (a[j] == i)
                    cout << "," << j;
            }
            cout << "}";
        }
    }
    cout << "\n";
}

int main()
{
    int count;
    cin >> count;
    char get;
    while (cin >> get && get != '-')
    {
        int m, n;
        if (get == 'U')
        {
            scanf("nion(%d,%d)", &m, &n);
            Union(m, n);
            Print_Union(m, n, count);
        }
        else
        {
            scanf("ind(%d), Find(%d)", &m, &n);
            printf("Find(%d), Find(%d): %s\n", m, n, (Find(m) == Find(n) ? "Yes" : "No"));
        }
    }

    system("pause");
    return 0;
}