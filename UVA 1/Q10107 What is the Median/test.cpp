#include <algorithm>
#include <iostream>

using namespace std;
int main()
{
    int a[10000], sum = 0;

    while (cin >> a[sum])
    {
        sort(a, a + sum + 1);
        /*  for (int i = 0; i <= sum; i++)
        {
            cout << "a[" << i << "] = " << a[i] << "\n";
        }       */
        //cout << "sum = " << sum << "\n";
        if (sum % 2)
            cout << (a[sum / 2] + a[sum / 2 + 1]) / 2 << "\n";
        else
            cout << a[sum / 2] << "\n";
        sum++;
    }

    system("pause");
    return 0;
}
