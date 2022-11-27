#include <bits/stdc++.h>

#define N 300
using namespace std;
int n, m, mp[N][N], color[N], res[N], ans;

void dfs(int u, int num) // u 當前的點 num 黑點數量
{
    if (u == n + 1)
    {
        if (num > ans)
        {
            ans = num;
            memcpy(res, color, sizeof(color));
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (mp[u][i] && color[i]) // u i 有相連且 i 為黑 -> u為白
        {
            dfs(u + 1, num);
            return;
        }
    }

    // 以下不確定顏色
    color[u] = 1;
    dfs(u + 1, num + 1);

    color[u] = 0;
    dfs(u + 1, num);
}

void output()
{
    cout << ans << "\n";
    int t = 0;
    for (int i = 1; i <= n; i++)
    {
        if (res[i])
        {
            t++;
            cout << i << " \n"[t == ans];
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ans = 0;
        memset(mp, 0, sizeof(mp));
        memset(color, 0, sizeof(color));

        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            mp[a][b] = mp[b][a] = 1;
        }

        dfs(1, 0);
        output();
    }

    system("pause");
    return 0;
}