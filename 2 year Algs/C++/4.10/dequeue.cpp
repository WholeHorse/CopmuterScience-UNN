#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define SIZE 6
using namespace std;
// переделать в динамический массив
class Dequeue {
    int buffer[SIZE];
    int start = -1;
    int end = -1;

    public:
    Dequeue() = default;

    bool IsEmpty() const {return end == -1 && start == -1;}
    bool IsFull() const {return ((end + 1) % SIZE == start);}

    void reset() {start = -1; end = -1;}

    bool push_front(int element){
        if(IsFull()) {
            cerr << "Queue is full! \n";
            return false;
            }
        if (IsEmpty()) start = end = 0;
        else start = (start - 1 + SIZE) % SIZE;
        buffer[start] = element;
        return true;
    }
    bool push_back(int element){
        if(IsFull()) {
            cerr << "Queue is full! \n";
            return false;
            }
        if (IsEmpty()) start = end = 0;
        else end = (end + 1) % SIZE;
        buffer[end] = element;
        return true;
    }

    bool pop_front(){
        if (IsEmpty()) return false;
        if (start == end) reset();
        else start = (start + 1) % SIZE;
        return true;
    }
    bool pop_back(){
        if (IsEmpty()) return false;
        if (start == end) reset();
        else end = (end - 1 + SIZE) % SIZE;
        return true;
    }

    int get_front() const {
        if(IsEmpty() == 1) exit(1);
        return buffer[start];
    }
    int get_back() const {
        if(IsEmpty()) exit(1);
        return buffer[end];
    }

    int size() const {
        if (IsEmpty()) return 0;
        return ((end - start + SIZE) % SIZE) + 1;
    }

    void print() const {
        if (IsEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = start; i != end; i = (i + 1) % SIZE)
            cout << buffer[i] << " ";
        cout << buffer[end] << endl;
    }
};

int main()
{
    Dequeue queue;
    for(int i = 0; i < 7; i++){
        queue.push_back(i);
    }
    queue.pop_back();
    queue.print();

    return 0;
}