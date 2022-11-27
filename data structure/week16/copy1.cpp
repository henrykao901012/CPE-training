#include <iostream>
#include <cstring>
using namespace std;
int dis[100], vis[100] = {0}, arr[10][10] = {0};

int main()
{
    int start, a, b, len, max = 0, i, j, end;
    cin >> start;
    while (cin >> a >> b >> len)
    {
        arr[a][b] = len;
        if (max < b)
            max = b;
        else if (max < a)
            max = a;
    }
    for (i = 0; i <= max; i++)
        dis[i] = 9999;
    dis[start] = 0;
    for (end = 0; end <= max; end++)
    {
        int min = 9999, curr = 0;
        for (i = 0; i <= max; i++)
        {
            if (arr[start][i] != 0 && vis[i] == 0)
                dis[i] = arr[start][i] + dis[start];
        }
        vis[start] = 1;
        for (i = 0; i <= max; i++)
        {
            if (vis[i] == 0 && dis[i] < min)
            {
                min = dis[i];
                curr = i;
            }
        }
        start = curr;
    }
    for (i = 0; i <= max; i++)
        cout << i << ": " << dis[i] << endl;
}