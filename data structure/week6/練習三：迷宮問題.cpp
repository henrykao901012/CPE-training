#include <iostream>

using namespace std;

char a[10][10];

void print_road(bool succeed)
{
    cout << (succeed ? "YES\n" : "NO\n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (!succeed && a[i][j] == 'G')
                a[i][j] = 'D';
            cout << a[i][j] << (j == 9 ? "\n" : " ");
        }
    }
    //cout << "\n";
}

void find_road(int x, int y)
{
    static bool found = 0;
    if (x == 1 && y == 1)
    {
        a[x][y] = 'X';
        found = 1;
        return;
    }
    if (a[x][y] == '0' && !found)
    {
        a[x][y] = 'G';
        //print_road();
        //if (a[x][y + 1] == '0')
        find_road(x, y + 1);
        //if (a[x - 1][y] == '0')
        find_road(x - 1, y);
        //if (a[x][y - 1] == '0')
        find_road(x, y - 1);
        //if (a[x + 1][y] == '0')
        find_road(x + 1, y);
    }
    if (a[x][y] == 'G')
    {
        a[x][y] == 'D';
        //print_road();
    }
}

int main()
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cin >> a[i][j];

    find_road(8, 8);
    bool suceed = a[1][1] == 'X';
    a[1][1] = 'X';
    a[8][8] = 'S';
    print_road(suceed);

    system("pause");
    return 0;
}