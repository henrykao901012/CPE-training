#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char str[1000000];
    int t = 0;
    while (gets(str))
    {
        for (int i = 0; str[i]; i++)
        {
            if (str[i] != '\"')
                cout << str[i];
            else
            {
                if (t % 2)
                    cout << "''";
                else
                    cout << "``";
                t++;
            }
        }
        cout << "\n";
    }

    system("pause");
    return 0;
}
//"To be or not to be," quoth the Bard, "that is the question".

//The programming contestant replied: "I must disagree. To `C' or not to `C', that is The Question!"
