#include "T_stack.h"

int main()
{
    Stack<int, 20> test1;
    Stack<float, 20> test2;

    cout << test1.isEmpty() << endl;
    cout << test1.isFull() << endl;
    for (int i = 1; i <= 15; i++)
    {
        test1.push(i);
    }
    cout << test1.isEmpty() << endl;
    cout << test1.isFull() << endl;
    test1.printStack();
    for (int i = 1; i <= 15; i++)
    {
        test1.pop();
    }
    cout << test1.isEmpty() << endl;
    cout << test1.isFull() << endl;
    test1.printStack();

    cout << endl;

    cout << test2.isEmpty() << endl;
    cout << test2.isFull() << endl;
    for (int i = 1; i <= 10; i++)
    {
        float tmp = i + 0.01f * i;
        test2.push(tmp);
    }
    cout << test2.isEmpty() << endl;
    cout << test2.isFull() << endl;
    test2.printStack();
    for (int i = 1; i <= 10; i++)
    {
        test2.pop();
    }
    cout << test2.isEmpty() << endl;
    cout << test2.isFull() << endl;
    test2.printStack();

    system("pause");
    return 0;
}