#include <algorithm>
#include <iostream>

using namespace std;
int main()
{
    int n, count = 1;
    cin >> n;
    while (n--)
    {
        printf("Case %d: ", count++);
        long long a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);

        if (a[0] + a[1] <= a[2])
            cout << "Invalid\n";
        else if (a[0] == a[1] && a[1] == a[2])
            cout << "Equilateral\n";
        else if (a[0] == a[1] || a[1] == a[2])
            cout << "Isosceles\n";
        else
            cout << "Scalene\n";
    }

    system("pause");
    return 0;
}
