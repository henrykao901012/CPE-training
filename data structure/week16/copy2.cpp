#include <iostream>
using namespace std;
#define min(x, y) (x < y) ? x : y;

int main()
{
    int a, b, len, max = 0, dis[10][10], arr[10][10], i, j, k;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            arr[i][j] = 9999;
        }
        arr[i][i] = 0;
    }
    while (cin >> a >> b >> len)
    {
        arr[a][b] = len;
        if (max < b)
            max = b;
    }
    for (i = 0; i <= max; i++)
    {
        for (j = 0; j <= max; j++)
        {
            if (j == 0)
                dis[i][j] = 0;
            else
                dis[i][j] = 9999;
        }
    }
    for (k = 1; k <= max; k++)
    { //最多k格邊
        if (k == 1)
        {
            for (i = 0; i <= max; i++)
                dis[k - 1][i] = arr[0][i];
        }
        else
        {
            for (i = 1; i <= max; i++)
            {
                for (j = 0; j <= max; j++)
                {
                    if (arr[j][i] != 9999)
                    {
                        dis[k - 1][i] = min(dis[k - 2][j] + arr[j][i], dis[k - 1][i]);
                    }
                }
            }
        }
    }
    for (i = 0; i < max; i++)
    {
        int count = 0;
        for (j = 0; j <= max; j++)
        {
            if (dis[i][j] == 9999)
                cout << " i";
            else if (count++ == 0)
                cout << dis[i][j];
            else
                cout << " " << dis[i][j];
        }
        cout << endl;
    }
}