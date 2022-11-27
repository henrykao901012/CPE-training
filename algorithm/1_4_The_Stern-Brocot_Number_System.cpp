#include <bits/stdc++.h>

using namespace std;

void tree(int Lx, int Ly, int Rx, int Ry, int Tx, int Ty)
{
    if (Lx + Rx == Tx && Ly + Ry == Ty)
    {
        cout << "\n";
        return;
    }
    if ((Lx + Rx) * Ty < (Ly + Ry) * Tx)
    {
        cout << "R";
        tree(Lx + Rx, Ly + Ry, Rx, Ry, Tx, Ty);
    }
    else
    {
        cout << "L";
        tree(Lx, Ly, Lx + Rx, Ly + Ry, Tx, Ty);
    }
}

int main()
{
    int a, b;
    while (cin >> a >> b && !(a == 1 && b == 1))
        tree(0, 1, 1, 0, a, b);
    system("pause");
    return 0;
}