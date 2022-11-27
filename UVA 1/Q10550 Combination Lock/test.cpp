#include <iostream>

using namespace std;
int main()
{
    int a, b, c, d;
    while (cin >> a >> b >> c >> d)
    {
        if (a + b + c + d == 0)
            break;
        int e[3];
        e[0] = a - b >= 0 ? a - b : a - b + 40;
        e[1] = c - b >= 0 ? c - b : c - b + 40;
        e[2] = c - d >= 0 ? c - d : c - d + 40;
        //cout << e[0] << " " << e[1] << " " << e[2] << "\n";
        cout << 9 * (e[0] + e[1] + e[2] + 120) << "\n";
    }

    system("pause");
    return 0;
}
