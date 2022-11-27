#include <iostream>

using namespace std;
int main()
{
    int n, a[100][100] = {0};
    cin >> n;
    int count = 1, x = n / 2, y = 0;
    while (count <= n * n)
    {
        a[y][x] = count++;
        int last_x = x, last_y = y;
        x++, y--;
        x += x < 0 ? n : (x >= n ? -n : 0);
        y += y < 0 ? n : (y >= n ? -n : 0);
        if (a[y][x] != 0)
            x = last_x, y = last_y + 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j];
            j == n - 1 ? cout << "\n" : cout << " ";
        }
    }

    system("pause");
    return 0;
}
