#include <iostream>
#include <cmath>
#define N 10
using namespace std;

class Stack
{
    char buffer[N];
    int top;

public:
    Stack() : top(-1) {}
    void push(char c)
    {
        if (top == N - 1)
        {
            cout << "Stack is full" << endl;
            return;
        }
        buffer[++top] = c;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        top--;
    }
    char topElement()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return '\0';
        }
        return buffer[top];
    }
    int size()
    {
        return top + 1;
    }
    bool IsEmpty()
    {
        return top == -1;
    }
    bool IsFull()
    {
        return top == N - 1;
    }
    void reset()
    {
        top = -1;
    }
    void print()
    {
        cout << "TOP = ";
        for (int i = 0; i <= top; i++)
            cout << buffer[i] << " -> ";
        cout << endl;
    }
};

int main()
{
    Stack st1;
    st1.push('A');
    st1.push('B');
    st1.push('C');
    cout << st1.topElement() << endl; // C
    cout << st1.size() << endl;       // 3
    st1.print();                      // TOP = A -> B -> C
    st1.pop();                        // удаление верхнего элемента
    cout << st1.topElement() << endl; // B
    cout << st1.size() << endl;       // 2
    st1.push('D');
    st1.print(); // TOP = A -> B -> D
    cout << st1.IsEmpty() << endl; // 0
    cout << st1.IsFull() << endl;  // 0
    st1.reset();                   // top = -1
    cout << st1.IsEmpty() << endl; // 1

    return 0;
}