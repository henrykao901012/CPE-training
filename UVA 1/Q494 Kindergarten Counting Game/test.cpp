#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    while (getline(cin, str))
    {
        bool isword = false;
        int count = 0;
        for (auto i : str)
        {
            //cout << i << " ";
            if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
                isword = true;
            else if (isword)
            {
                isword = false;
                count++;
            }
        }
        cout << count + isword << "\n";
    }
    system("pause");
    return 0;
}
/*
    Meep Meep!
    I tot I taw a putty tat.
    I did! I did! I did taw a putty tat.
    Shsssssssssh ... I am hunting wabbits. Heh Heh Heh Heh ...
*/