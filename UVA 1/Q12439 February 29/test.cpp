#include <iostream>

using namespace std;
int main()
{
    int t, count = 1;
    cin >> t;
    while (t--)
    {
        string month;
        cin >> month;

        int date, year;
        scanf("%d, %d", &date, &year);

        year -= month == "January" || month == "February";
        //year -= month == "January" || (month == "February" && date != 29);
        int t1 = year / 4 - year / 100 + year / 400;

        cin >> month;
        scanf("%d, %d", &date, &year);

        //year -= month == "January" || month == "February";
        year -= month == "January" || (month == "February" && date != 29);
        int t2 = year / 4 - year / 100 + year / 400;

        printf("Case %d: %d\n", count++, t2 - t1);
    }

    system("pause");
    return 0;
}

//    stuck!!!!