#include <iostream>

using namespace std;
int main()
{
    int h, m;
    while (scanf("%d:%d", &h, &m) == 2)
    {
        if (h + m == 0)
            break;
        //cout << h << " " << m << '\n';
        double hr = h * 30.0f + m * 0.5f;
        double min = m * 6.0f;
        double ang = hr - min;
        //cout << hr << " " << min << "\n";
        if (ang < 0)
            ang *= -1;
        if (ang > 180)
            ang = 360 - ang;
        printf("%.3lf\n", ang);
    }

    system("pause");
    return 0;
}
/* 
    12:00
    9:00
    8:10
    0:00 
*/