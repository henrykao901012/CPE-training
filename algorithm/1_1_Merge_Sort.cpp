#include <bits/stdc++.h>

using namespace std;
const int inf = numeric_limits<int>::max();

void merge(vector<int> &arr, int front, int mid, int end)
{
    vector<int> left(arr.begin() + front, arr.begin() + mid + 1),
        right(arr.begin() + mid + 1, arr.begin() + end + 1);
    left.push_back(inf);
    right.push_back(inf);
    int l = 0, r = 0;
    for (int i = front; i <= end; i++)
    {
        if (left[l] <= right[r])
            arr[i] = left[l++];
        else
            arr[i] = right[r++];
    }
}

void merge_sort(vector<int> &arr, int front, int end)
{
    if (front < end)
    {
        int mid = (front + end) / 2;
        merge_sort(arr, front, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, front, mid, end);
    }
}

int main()
{
    string str;
    getline(cin, str);
    stringstream buf(str);
    vector<int> arr;
    while (buf >> str)
        arr.push_back(stoi(str));

    merge_sort(arr, 0, arr.size() - 1);

    for (auto i : arr)
        cout << i << " ";
    cout << "\n";
    system("pause");
    return 0;
}