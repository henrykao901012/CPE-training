#include <iostream>

using namespace std;
int main()
{
    const int last = 5;
    const string week[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    const int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int n;
    cin >> n;
    while (n--)
    {
        int m, d;
        cin >> m >> d;

        int total = 0;
        for (int i = 0; i < m - 1; i++)
            total += month_days[i];

        cout << week[((total + d - 1) % 7 + last) % 7] << "\n";
    }

    system("pause");
    return 0;
}

//  2010/12/31 是禮拜六