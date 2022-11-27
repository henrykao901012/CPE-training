#include <iostream>
#include <stack>

using namespace std;

int bracket_check(string str)
{
    stack<bool> st;
    for (auto i : str)
    {
        //cout << i << " ";
        if (i == '(')
            st.push(1);
        else
        {
            if (st.empty())
                return -1;
            else
                st.pop();
        }
    }
    return st.empty() ? 1 : -1;
}

int main()
{
    string str;
    while (cin >> str && str != "end")
    {
        cout << bracket_check(str) << "\n";
    }

    system("pause");
    return 0;
}

/*
 try
        {
            for (auto i : str)
            {
                //cout << i << " ";
                if (i == '(')
                    st.push(1);
                else
                {
                    if (st.empty())
                        throw -1;
                    else
                        st.pop();
                }
            }
            throw st.empty() ? 1 : -1;
        }
        catch (int &e)
        {
            cout << e << "\n";
        }
*/
