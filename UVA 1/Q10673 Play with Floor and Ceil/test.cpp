#include <cmath>
#include <iostream>

using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x, k;
        cin >> x >> k;

        //double fl = floor((double)x / k);  其實不需要
        //double ce = ceil((double)x / k);

        if (x % k)
            cout << k - x % k << " " << x % k << "\n";
        else
            cout << k << " 0\n";
    }

    system("pause");
    return 0;
}
