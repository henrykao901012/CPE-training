#include <bits/stdc++.h>

using namespace std;

class binary_tree
{
private:
    void deep_count_function_only_call_by_deep(binary_tree *, int &, int = 0);

public:
    string str;
    binary_tree *left, *right;
    binary_tree(string get_str = "", binary_tree *lpos = 0, binary_tree *rpos = 0) : str(get_str), left(lpos), right(rpos) {}

    void insert(binary_tree *&, string, string);

    void preorder(binary_tree *);
    void inorder(binary_tree *);
    void postorder(binary_tree *);

    int deep(binary_tree *);
};

void binary_tree::insert(binary_tree *&start, string root, string add)
{
    if (!start)
        return;
    if (start->str == root)
    {
        (add[2] % 2 ? start->left : start->right) = new binary_tree(add);
        return;
    }
    if (start)
    {
        insert(start->left, root, add);
        insert(start->right, root, add);
    }
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

void binary_tree::inorder(binary_tree *start)
{
    if (start)
    {
        inorder(start->left);
        cout << start->str << " ";
        inorder(start->right);
    }
}

void binary_tree::postorder(binary_tree *start)
{
    if (start)
    {
        postorder(start->left);
        postorder(start->right);
        cout << start->str << " ";
    }
}

void binary_tree::deep_count_function_only_call_by_deep(binary_tree *start, int &max, int deep)
{
    //static int max = 0;
    //deep++;
    if (start)
    {
        //cout << start->str << " count = " << count << "\n";
        max = deep > max ? deep : max;
        deep_count_function_only_call_by_deep(start->left, max, deep + 1);
        deep_count_function_only_call_by_deep(start->right, max, deep + 1);
    }
    //deep--;
}

int binary_tree::deep(binary_tree *start)
{
    int max = 0;
    deep_count_function_only_call_by_deep(start, max);
    return max;
}

int main()
{
    binary_tree binary_tree_lib, *start = 0;
    stringstream buf;
    string s;
    while (getline(cin, s) && s != "0")
    {
        buf.clear();
        buf << s;
        string root;
        buf >> root;
        /*
        cout << "root = " << root << " node = ";
        while (buf >> s)
            cout << s << " ";
        cout << "\n";
        */
        if (root == "r")
            start = new binary_tree(root);
        while (buf >> s)
            binary_tree_lib.insert(start, root, s);
    }

    cout << "Preorder: ";
    binary_tree_lib.preorder(start);
    cout << "\n";

    cout << "Inorder: ";
    binary_tree_lib.inorder(start);
    cout << "\n";

    cout << "Postorder: ";
    binary_tree_lib.postorder(start);
    cout << "\n";

    cout << "The balance factor is " << abs(binary_tree_lib.deep(start->left) - binary_tree_lib.deep(start->right)) << "\n";

    system("pause");
    return 0;
}