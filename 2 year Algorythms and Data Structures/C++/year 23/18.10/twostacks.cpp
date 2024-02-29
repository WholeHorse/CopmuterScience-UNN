#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
using namespace std;
template <class T>
// динамическа двусторонняя очередь через два динамических стека
// 
class Queue {
    stack<T> l, r;
    int size = 0; //колво элементов или stack size

    public:
    Queue() = default;
    void add(int item) {
        l.push(item);
    }

    int del() {
        if (r.empty()) {
            while (!l.empty()) {
                r.push(l.top());
                l.pop();
            }
        }

        if (r.empty()) {
            ;
        }

        int item = r.top();
        r.pop();
        return item;
    }

    void print() {  
        stack<int> temp = r;
        while (!l.empty()) {
            temp.push(l.top());
            l.pop();
        }
        
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        
        cout << endl;
    }
};

int main()
{
    Queue<int> queue;
    for(int i = 0; i < 8; i++){
        queue.add(i);
    }
    queue.print();

    return 0;
}