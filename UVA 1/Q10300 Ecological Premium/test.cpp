#include <iostream>

using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int f;
        cin >> f;
        int data[20][3], sum = 0;
        for (int i = 0; i < f; i++)
        {
            cin >> data[i][0] >> data[i][1] >> data[i][2];
            sum += data[i][0] * data[i][2];
        }
        cout << sum << "\n";
    }

    system("pause");
    return 0;
}
