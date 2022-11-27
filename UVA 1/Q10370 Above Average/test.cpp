#include <iostream>

using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        double data[1000], sum = 0;
        int count, percent_count = 0;
        cin >> count;
        for (int i = 0; i < count; i++)
        {
            cin >> data[i];
            sum += data[i];
        }
        double med = sum / count;
        for (int i = 0; i < count; i++)
        {
            if (data[i] > med)
                percent_count++;
        }
        printf("%.3lf%\n", (double)percent_count / count * 100);
    }

    system("pause");
    return 0;
}
