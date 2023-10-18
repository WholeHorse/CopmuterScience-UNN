#include <iostream>
using namespace std;

class Dequeue {
    int *buffer;
    int SIZE;
    int start = -1;
    int end = -1;

    public:
    Dequeue(int size = 6) : SIZE(size) {
        buffer = new int[SIZE];
    }

    Dequeue(const Dequeue& other) : SIZE(other.SIZE), start(other.start), end(other.end) {
        buffer = new int[SIZE];
        memcpy(buffer, other.buffer, SIZE * sizeof(int));
    }

    Dequeue& operator=(const Dequeue& other) {
        if (this != &other) {
            delete[] buffer;
            SIZE = other.SIZE;
            start = other.start;
            end = other.end;
            buffer = new int[SIZE];
            copy(other.buffer, other.buffer + SIZE, buffer);
        }
        return *this;
    }

    ~Dequeue() {
        delete[] buffer;
    }

    bool IsEmpty() const {return end == -1 && start == -1;}

    bool IsFull() const {return ((end + 1) % SIZE == start);}

    void reset() {start = -1; end = -1;}

    void resize(int new_size) {
        int* new_buffer = new int[new_size];
        int current_size = size();
        for (int i = 0; i < current_size; ++i) {
            new_buffer[i] = buffer[(start + i) % SIZE];
        }
        delete[] buffer;
        buffer = new_buffer;
        SIZE = new_size;
        start = 0;
        end = current_size - 1;
    }

    bool push_front(int element){
        if(IsFull()) {
            resize(SIZE * 2);
            }
        if (IsEmpty()) start = end = 0;
        else start = (start - 1 + SIZE) % SIZE;
        buffer[start] = element;
        return true;
    }

    bool push_back(int element){
        if(IsFull()) {
            resize(SIZE * 2);
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
    Dequeue queue1;
    for(int i = 0; i < 7; i++){
        queue1.push_back(i);
    }
    Dequeue queue2 = queue1;

    queue2.print();
    queue1.reset();
    queue2.print();

    return 0;
}