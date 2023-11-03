#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class LinkedList{
    int element;
    LinkedList * next = NULL;
    LinkedList * prev = NULL;
    static LinkedList * head;
    static LinkedList * tail;
    static int counter;

    LinkedList(int n): element(n){
        counter++;
    }
    ~LinkedList(){
        counter--;
    }
    public:

    static bool IsEmpty(){
        return counter == 0;
    }

    static int get_size(){
        return counter;
    }

    static void print(){
        if(IsEmpty()) return ;
        LinkedList * p = head;
        cout<<"head-> ";
        while(p){
            cout<<p->element<<" ";
            p = p->next;
        }
        cout<<"<-tail"<<endl;
    }

    static bool push_front(int n){
        LinkedList * p = new LinkedList(n);
        if(!p) return false;
        if(IsEmpty()){
            head = tail = p;
        }
        else{
            head->prev = p;
            p->next = head;
            head = p;
        }
        return true;
    }

    static bool push_back();

    static bool pop_front(){
        if (IsEmpty()) return false;
        LinkedList* temp = head;
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        delete temp;
        return true;
    }  

    static bool pop_back();

    static bool erase_element(int n){

    }

    static bool delete_list(){

    }
};

LinkedList * LinkedList::head = NULL;
LinkedList * LinkedList::tail = NULL;
int LinkedList::counter = 0;

int main()
{
    LinkedList::push_front(10);
    LinkedList::push_front(20);
    LinkedList::push_front(30);
    LinkedList::pop_front();
    LinkedList::print();
    cout << LinkedList::get_size() << endl;
    return 0; 
}