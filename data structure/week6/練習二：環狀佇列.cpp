#include <iostream>
#include <vector>

using namespace std;

class circular_queue
{
public:
    circular_queue(int);
    int arr[100];
    unsigned int front, rear, MAX_QUEUE_SIZE;
    bool isFull();
    bool isEmpty();
    void addq(int);
    void deq();
    inline static const string Empty_Error = "EMPTY";
    inline static const string Full_Error = "FULL";
};

circular_queue::circular_queue(int size)
{
    front = rear = 0;
    MAX_QUEUE_SIZE = size;
}

bool circular_queue::isEmpty()
{
    return front == rear;
}

bool circular_queue::isFull()
{
    return (rear + 1) % MAX_QUEUE_SIZE == front;
}

void circular_queue::addq(int num)
{
    if (isFull())
        throw circular_queue::Full_Error;
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    arr[rear] = num;
}

void circular_queue::deq()
{
    if (isEmpty())
        throw circular_queue::Empty_Error;
    front = (front + 1) % MAX_QUEUE_SIZE;
    throw arr[front];
}

int main()
{
    int n;
    cin >> n;
    circular_queue que(n);

    int get;
    while (cin >> get && get != -1)
    {
        if (get)
        {
            int num;
            cin >> num;
            try
            {
                que.addq(num);
            }
            catch (string &str)
            {
                cout << str << "\n";
            }
        }
        else
        {
            try
            {
                que.deq();
            }
            catch (string &str)
            {
                cout << str << "\n";
            }
            catch (int &num)
            {
                cout << num << "\n";
            }
        }
    }

    system("pause");
    return 0;
}