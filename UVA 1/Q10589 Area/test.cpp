#include <iostream>

using namespace std;

int main()
{
    int n, a;
    while (cin >> n >> a)
    {
        if (!n)
            break;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            double x, y;
            cin >> x >> y;
            if ((x * x + y * y <= a * a) && ((x - a) * (x - a) + y * y <= a * a) && (x * x + (y - a) * (y - a) <= a * a) && ((x - a) * (x - a) + (y - a) * (y - a) <= a * a))
                sum++;
            //cout << "sum = " << sum << "\n";
        }
        //cout << (double)(sum / n) << "\n";   不能先括號
        printf("%.5lf\n", (double)sum / n * a * a);
    }

    system("pause");
    return 0;
}
