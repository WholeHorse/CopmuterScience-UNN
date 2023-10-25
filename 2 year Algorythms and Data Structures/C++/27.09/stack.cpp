#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10
#include <iostream>
#include <string.h>
using namespace std;

class Stack{
    int * buffer = new int[SIZE];
    int size = SIZE;
    int top = -1;

    public:
    Stack() = default;

    Stack(const Stack & r) 
    : buffer(new int [r.size]), size(r.size), top(r.top){
        memcpy(buffer, r.buffer, sizeof(int) * (top + 1));
    }

    ~Stack(){
        delete [] buffer;
    }

    bool IsEmpty() const{
        return top == -1;
    }
    bool IsFull() const{
        return top == size - 1;
    }

    int get_top(){
        if(!IsEmpty()){
            return buffer[top];
        }
        cerr << "Stack is empty xd" << endl;
        exit(1);
    }

    void reset(){
        top = -1;
    }

    bool pop(){
        if(IsEmpty()){
            cout << "Stack is empty xd" << endl;
            return false;
        }
        --top;
        return true;
    }

    bool push(int const & element){
        if(IsFull()){
            int * new_buffer = new int[size *= 2];
            if(!new_buffer) return false;
            memcpy(new_buffer, buffer, sizeof(int) * (top + 1));
            delete [] buffer;
            buffer = new_buffer;
        }
        buffer[++top] = element;
        return true;
    }

    void print() const{
        if(IsEmpty()) cout << "Stack is empty xd" << endl;
        else{
        cout << "Stack from top: ";
            for(int i = top; i >= 0; --i){
                cout << buffer[i];
                if(i > 0) cout << " -> ";
            }
            cout << endl;
        }
    }

    Stack operator = (Stack & r){
        if(this == &r) return *this;

        if(r.size <= size) { 
            memcpy(buffer, r.buffer, sizeof(int) * (r.top + 1)); 
            top = r.top;
        } 
        else { 
            delete [] buffer;
            buffer = new int[r.size];
            size = r.size;
            top = r.top;
            memcpy(buffer, r.buffer, sizeof(int) * (top + 1));
        }

        return *this;
    }

};

int main()
{
    Stack st1, st2;
    for(int i = 0; i < 32; i++)
        st1.push(i);
    st2 = st1;
    st1.print();
    st2.print();
    st1.reset();
    st1.print();
    st2.print();
    

    return 0;
}