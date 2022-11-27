#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> vec;
    while (n--)
    {
        int num;
        cin >> num;
        vec.push_back(num);
    }

    for (int i = 1; i < vec.size(); i++)
    {
        if (i == 2)
            cout << vec[0] << " " << vec[1] << "\n";
        else if (i == 3)
            cout << vec[0] << " " << vec[1] << " " << vec[2] << "\n";

        for (int j = 0; j < i; j++)
        {
            //cout << i << "  : " << vec[i] << "  " << j << " : " << vec[j] << " bool : " << (vec[i] < vec[j]) << "\n";
            if (vec[i] < vec[j])
            {
                vec.insert(vec.begin() + j, vec[i]);
                vec.erase(vec.begin() + i + 1);
                break;
            }
        }
    }

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
        i == vec.size() - 1 ? cout << "\n" : cout << " ";
    }

    system("pause");
    return 0;
}
