#include <iostream>
#include <math.h>

using namespace std;
int main()
{

    double pi = 2.0 * acos(0.0);
    double a;
    while (cin >> a)
    {
        double z = a * a * (1 - sqrt(3.0) / 4 - pi / 6.0);
        double y = a * a * (1 - pi / 4) - z * 2;
        double x = a * a - (y + z) * 4;
        printf("%.3lf %.3lf %.3lf\n", x, y * 4, z * 4);
        //cout << x << " " << y * 4 << " " << z * 4 << "\n";
    }

    system("pause");
    return 0;
}
