#include <bits/stdc++.h>

using namespace std;

stringstream buf;
vector<int> ans;

class binary_tree
{
public:
    string str;
    binary_tree *left, *right;
    binary_tree(string get_str = "", binary_tree *lpos = 0, binary_tree *rpos = 0) : str(get_str), left(lpos), right(rpos) {}

    void insert(binary_tree *&, string);

    void preorder(binary_tree *);
    void inorder(binary_tree *);
    void postorder(binary_tree *);
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
        ans.push_back(stoi(start->str));
        preorder(start->left);
        preorder(start->right);
    }
}

void binary_tree::inorder(binary_tree *start)
{
    if (start)
    {
        inorder(start->left);
        ans.push_back(stoi(start->str));
        inorder(start->right);
    }
}

void binary_tree::postorder(binary_tree *start)
{
    if (start)
    {
        postorder(start->left);
        postorder(start->right);
        ans.push_back(stoi(start->str));
    }
}

int main()
{
    binary_tree binary_tree_lib, *start = 0;
    string s;
    getline(cin, s);
    buf << s;
    int get, size = 0;
    cin >> get;

    while (buf >> s)
    {
        binary_tree_lib.insert(start, s);
        size++;
    }

    binary_tree_lib.inorder(start);
    binary_tree_lib.preorder(start);
    binary_tree_lib.postorder(start);

    for (int i = 0; i < 3; i++)
        cout << ans[distance(ans.begin(), find(ans.begin() + i * size, ans.begin() + (i + 1) * size, get)) + 1]
             << " \n"[i == 2];

    system("pause");
    return 0;
}