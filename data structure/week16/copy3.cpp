#include <iostream>
using namespace std;

int main()
{
    int n, arr[10][10], i, j, d[100] = {0}, start, max = 0;
    cin >> n;
    for (i = 0; i < n; i++) //輸入
        for (j = 0; j < n; j++)
            cin >> arr[i][j];

    for (start = 0; start < n; start++)
    {
        for (i = 0; i < n; i++)
            d[i] = 9999; //先把出值都設無線大
        d[start] = 0;    //start到start=0
        for (int end = 0; end < n; end++)
        { //計算start直接到end的長度
            if (arr[start][end] != 0)
                d[end] = arr[start][end];
        }
        for (int k = 0; k < n; k++)
        {
            for (i = 0; i < n; i++)
            {
                if (d[i] != 9999)
                { //找到已被找過的點
                    for (j = 0; j < n; j++)
                    {
                        if (arr[i][j] != 0 && d[i] + arr[i][j] < d[j])
                        { //找與點相連的最短距離
                            d[j] = d[i] + arr[i][j];
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (d[i] > max)
            max = d[i];
    }
    cout << max << endl;
}