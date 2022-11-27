#include <iostream>

using namespace std;
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int a, f;
        cin >> a >> f;
        for (int fre = 1; fre <= f; fre++)
        {
            for (int j = 1; j <= a; j++)
            {
                for (int k = 1; k <= j; k++)
                    cout << j;
                cout << "\n";
            }
            for (int j = a - 1; j >= 1; j--)
            {
                for (int k = 1; k <= j; k++)
                    cout << j;
                cout << "\n";
            }
            if (fre != f)
                cout << "\n";
        }
        if (i != n)
            cout << "\n";
    }

    system("pause");
    return 0;
}
/*
2
3
2
5
3
*/