#include <iostream>
#include <vector>

using namespace std;

class sparse_matrix_list
{
public:
   int ud, rl, num;
};

int main()
{
   int a, b;
   cin >> a >> b;

   vector<sparse_matrix_list> mylist;
   int count = 0;
   for (int i = 0; i < a; i++)
   {
      for (int j = 0; j < b; j++)
      {
         int num;
         cin >> num;
         if (num)
         {
            sparse_matrix_list get = {i, j, num};
            mylist.push_back(get);
            count++;
         }
      }
   }

   cout << a << " " << b << " " << count << "\n";
   for (auto i : mylist)
      cout << i.ud << " " << i.rl << " " << i.num << "\n";

   system("pause");
   return 0;
}
