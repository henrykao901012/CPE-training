#include <iostream>
#include <limits>
using namespace std;

void jump_str(int n)
{
    for (int i = 0; i < n; i++)
    {
        string str;
        getline(cin, str);
    }
}
int main()
{
    int n, p, count = 1;
    while (cin >> n >> p)
    {
        if (n + p == 0)
            break;
        getchar();
        jump_str(n);
        if (count - 1)
            cout << "\n";
        string co_name;
        double confirm_money = numeric_limits<double>().max();
        int confirm_check = 0;
        for (int i = 0; i < p; i++)
        {
            string name;
            double money;
            int check;

            getline(cin, name);
            cin >> money >> check;
            getchar();
            jump_str(check);

            if (check > confirm_check || (check == confirm_check && (double)money / check < confirm_money))
            {
                co_name = name;
                confirm_check = check;
                confirm_money = (double)money / check;
            }
        }
        printf("RFP #%d\n%s\n", count, co_name.c_str());
        count++;
    }

    system("pause");
    return 0;
}
