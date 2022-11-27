#include <bits/stdc++.h>

using namespace std;
stringstream buf;

class binary_tree
{
private:
    void find_pos_data_function_only_call_by_del(binary_tree *, binary_tree **&, string);

public:
    string str;
    binary_tree *left, *right;
    binary_tree(string get_str = "", binary_tree *lpos = 0, binary_tree *rpos = 0) : str(get_str), left(lpos), right(rpos) {}

    void insert(binary_tree *&, string);

    void del(binary_tree *&, string);

    void preorder(binary_tree *);
};

void binary_tree::find_pos_data_function_only_call_by_del(binary_tree *start, binary_tree **&pos, string s)
{
    if (pos || !start)
        return;
    if (start->str == s)
    {
        pos = &start;
        return;
    }
    if (start->left && start->left->str == s)
        pos = &start->left;

    if (start->right && start->right->str == s)
        pos = &start->right;

    find_pos_data_function_only_call_by_del(start->left, pos, s);
    find_pos_data_function_only_call_by_del(start->right, pos, s);
}

void binary_tree::del(binary_tree *&start, string s)
{
    binary_tree **pre_pos_pointer = 0;
    find_pos_data_function_only_call_by_del(start, pre_pos_pointer, s);
    if (!pre_pos_pointer)
        throw "no " + s;

    if ((*pre_pos_pointer)->left && (*pre_pos_pointer)->right)
    {
        binary_tree **find_pre_max = &(*pre_pos_pointer)->left;
        while ((*find_pre_max)->right)
            find_pre_max = &(*find_pre_max)->right;
        (*pre_pos_pointer)->str = (*find_pre_max)->str;
        binary_tree *ready_to_del = *find_pre_max;
        *find_pre_max = (*find_pre_max)->left;
        delete ready_to_del;
    }
    else
    {
        binary_tree *ready_to_del = *pre_pos_pointer;
        *pre_pos_pointer = ready_to_del->left ? ready_to_del->left : ready_to_del->right;
        delete ready_to_del;
    }
}

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
    getline(cin, s);
    buf << s;
    while (buf >> s)
        binary_tree_lib.insert(start, s);

    getline(cin, s);
    buf.clear();
    buf.str("");
    buf << s;

    cout << "Binary search tree (before):\n";
    binary_tree_lib.preorder(start);
    cout << "\n";
    while (buf >> s)
    {
        try
        {
            binary_tree_lib.del(start, s);
        }
        catch (const string str)
        {
            cout << str << "\n";
        }
    }
    cout << "Binary search tree (after):\n";
    binary_tree_lib.preorder(start);
    cout << "\n";

    system("pause");
    return 0;
}