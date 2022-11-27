#include <bits/stdc++.h>

using namespace std;

struct node
{
    int x, y;
    node(){};
    node(int tx, int ty) : x(tx), y(ty) {}
};
queue<node> q;
int X, Y, sx, sy, ex, ey;
int dir[][2] = {
    {-1, 0}, //上
    {-1, 1}, //右上
    {0, 1},  //右
    {1, 1},  //右下
    {1, 0},  //下
    {1, -1}, //左下
    {0, -1}, //左
    {-1, -1} //左上
};
int road[1000][1000];
node path[1000][1000];

void bfs(int x, int y)
{
    q.push(node(x, y));
    while (!q.empty())
    {
        node get = q.front();
        q.pop();
        if (get.x == ex && get.y == ey)
        {
            path[999][999] = node(ex, ey);
            return;
        }
        for (int i = 0; i < 8; i++)
        {
            int tx = get.x + dir[i][0];
            int ty = get.y + dir[i][1];
            if (tx < 0 || tx >= X || ty < 0 || ty >= Y || road[tx][ty] == 1)
                continue;
            path[tx][ty] = get; // path record the next node
            q.push(node(tx, ty));
            road[tx][ty] = 1; // already go through
        }
    }
}

void outpath()
{
    char buf[1000][20];
    int m = 999, n = 999, count = 0;
    while (1)
    {
        sprintf(buf[count++], "(%d,%d)\n", path[m][n].x + 1, path[m][n].y + 1);
        if (path[m][n].x == sx && path[m][n].y == sy)
            break;
        int t = m;
        m = path[m][n].x;
        n = path[t][n].y;
    }
    cout << count << "\n";
    while (count--)
        printf("%s", buf[count]);
}

int main()
{
    cin >> X >> Y >> sx >> sy >> ex >> ey;
    sx--, sy--, ex--, ey--;
    for (int i = 0; i < X; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < Y; j++)
        {
            road[i][j] = str[j] - '0';
            path[i][j] = node(0, 0);
        }
    }

    bfs(sx, sy);
    outpath();

    system("pause");
    return 0;
}