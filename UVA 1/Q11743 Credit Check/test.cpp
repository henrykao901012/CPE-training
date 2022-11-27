#include <iostream>

using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string str[4];
        cin >> str[0] >> str[1] >> str[2] >> str[3];

        int sum = 0;
        for (int i = 0; i < 4; i++)
        {
            int zero = (str[i][0] - '0') * 2;
            int second = (str[i][2] - '0') * 2;
            sum += zero % 10 + zero / 10 + second % 10 + second / 10 + str[i][1] - '0' + str[i][3] - '0';
        }
        //cout << sum << "\n";
        sum % 10 ? cout << "Invalid\n" : cout << "Valid\n";
    }

    system("pause");
    return 0;
}
