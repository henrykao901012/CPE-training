#include <iostream>

using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int j = 1; j <= n; j++)
    {
        int a, b, sum = 0;
        cin >> a >> b;
        for (int i = a; i <= b; i++)
            if (i % 2)
                sum += i;
        printf("Case %d: %d\n", j, sum);
    }

    system("pause");
    return 0;
}
