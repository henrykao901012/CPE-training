#include <iostream>

using namespace std;
int main()
{
    int n;

    while (cin >> n)
    {
        for (int i = 2; i <= n; i++)
        {
            int sum = 0;
            while (n % i == 0)
            {
                sum++;
                n /= i;
            }
            if (sum)
            {
                if (sum > 1)
                    printf("%d^%d", i, sum);
                else
                    cout << i;
                if (n != 1)
                    cout << " * ";
            }
        }
        cout << "\n";
    }

    system("pause");
    return 0;
}
