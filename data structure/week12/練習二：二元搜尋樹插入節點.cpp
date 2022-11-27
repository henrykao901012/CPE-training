#include <bits/stdc++.h>

using namespace std;

class binary_tree
{
public:
    string str;
    binary_tree *left, *right;
    binary_tree(string get_str = "", binary_tree *lpos = 0, binary_tree *rpos = 0) : str(get_str), left(lpos), right(rpos) {}

    void insert(binary_tree *&, string);

    void preorder(binary_tree *);
};

void binary_tree::insert(binary_tree *&start, string add)
{
    if (!start)
    {
        start = new binary_tree(add);
        return;
    }
    binary_tree **get = stoi(add) > stoi(start->str) ? &start->right : &start->left;
    if (!*get)
    {
        *get = new binary_tree(add);
        return;
    }
    insert(*get, add);
}

void binary_tree::preorder(binary_tree *start)
{
    if (start)
    {
        cout << start->str << " ";
        preorder(start->left);
        preorder(start->right);
    }
}

int main()
{
    binary_tree binary_tree_lib, *start = 0;
    string s;
    while (cin >> s)
    {
        binary_tree_lib.insert(start, s);
        binary_tree_lib.preorder(start);
        cout << "\n";
    }

    system("pause");
    return 0;
}