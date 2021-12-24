#include <iostream>
using namespace std;

#define n 20

class Queue
{
    int *arr;
    int front;
    int back;

public:
    Queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void push(int data)
    {
        if (n == back - 1)
        {
            cout << "Queue is full" << endl;
            return;
        }
        back++;
        arr[back] = data;

        if (front == -1)
        {
            front++;
        }
    }

    void pop()
    {
        if (front == -1 || front > back)
        {
            cout << "No element to delete" << endl;
            return;
        }
        front++;
    }

    void peek()
    {
        if (front == -1 || front > back)
        {
            cout << "No element in the queue" << endl;
            return;
        }
        cout << arr[front] << endl;
    }
    bool empty()
    {
        if (front > back || front == -1)
        {
            return 1;
        }
        return 0;
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);

    q.pop();
    q.pop();
    cout << q.empty() << endl;
    return 0;
}