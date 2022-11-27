#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
   int t = a;
   a = b;
   b = t;
}
void slection_sort(vector<int> &arr)
{
   for (int j = 0; j < arr.size(); j++)
   {
      int min = j;
      for (int i = j + 1; i < arr.size(); i++)
      {
         if (arr[i] < arr[min])
            min = i;
      }
      swap(arr[j], arr[min]);
   }
}
int main()
{
   int n;
   cin >> n;
   vector<int> vec;
   for (int i = 0; i < n; i++)
   {
      int num;
      cin >> num;
      vec.push_back(num);
   }

   slection_sort(vec);

   for (int i = 0; i < vec.size(); i++)
   {
      cout << vec[i];
      i == vec.size() - 1 ? cout << "\n" : cout << " ";
   }
   system("pause");
   return 0;
}
