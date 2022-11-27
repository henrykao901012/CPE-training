#include <iostream>
#include <vector>

using namespace std;

int binsearch(vector<int> &vec, int n)
{
    int left = 0, right = vec.size() - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (vec[middle] == n)
            return middle;
        else if (vec[middle] < n)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec;
    while (k--)
    {
        int num;
        cin >> num;
        vec.push_back(num);
    }
    cout << binsearch(vec, n) << "\n";

    system("pause");
    return 0;
}
