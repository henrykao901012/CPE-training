#include <iostream>

using namespace std;
int main()
{
    int n, h[100], set = 1;
    while (cin >> n && n)
    {
        int avg = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
            avg += h[i];
        }
        avg /= n;
        for (int i = 0; i < n; i++)
        {
            int get = h[i] - avg >= 0 ? h[i] - avg : avg - h[i];
            sum += get;
        }
        sum /= 2;
        printf("Set #%d\nThe minimum number of moves is %d.\n\n", set, sum);
        set++;
    }

    system("pause");
    return 0;
}
/*
    6
    5 2 4 1 7 5
    3
    1 1 1
    0
*/