#include <iostream>
#include <string>

using namespace std;
int main()
{
    string str;
    while (getline(cin, str))
    {
        string data = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
        for (auto i : str)
        {
            if (i == ' ')
                cout << i;
            else
            {
                for (int j = 0; data[j]; j++)
                {
                    if (i == data[j])
                    {
                        cout << data[j - 1];
                        break;
                    }
                }
            }
        }
        cout << "\n";
    }

    system("pause");
    return 0;
}
