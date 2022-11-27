#include <iostream>

using namespace std;
int main()
{
    char data[] = "qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

    string str;
    while (getline(cin, str))
    {
        for (auto i : str)
        {
            if (isupper(i))
                i = tolower(i);
            for (int j = 0; data[j]; j++)
            {
                if (i == data[j])
                {
                    i = data[j - 2];
                    break;
                }
            }
            cout << i;
        }
        cout << "\n";
    }
    system("pause");
    return 0;
}
