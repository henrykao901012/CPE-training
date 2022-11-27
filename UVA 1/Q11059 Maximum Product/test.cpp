#include <iostream>

using namespace std;
int main()
{
    int n, count = 1;
    while (cin >> n)
    {
        int num[20];
        for (int i = 0; i < n; i++)
            cin >> num[i];

        long long max = 0;
        for (int i = 0; i < n; i++)
        {
            long long t = 1;
            for (int j = i; j < n; j++)
            {
                t *= num[j];
                if (t > max)
                    max = t;
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n", count, max);
        count++;
    }

    system("pause");
    return 0;
}
