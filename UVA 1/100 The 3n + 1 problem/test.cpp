#include <iostream>
using namespace std;

int F(int num, int sum)
{
    if (num == 1)
        return sum;
    if (num % 2)
        return F(3 * num + 1, ++sum);
    return F(num / 2, ++sum);
}
int getmax(int a, int b)
{
    return a >= b ? a : b;
}
int getmin(int a, int b)
{
    return a >= b ? b : a;
}
int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        int max = 0;
        for (int i = getmin(a, b); i <= getmax(a, b); i++)
        {
            if (F(i, 1) > max)
                max = F(i, 1);
        }
        cout << a << " " << b << " " << max << "\n";
    }

    system("pause");
    return 0;
}
