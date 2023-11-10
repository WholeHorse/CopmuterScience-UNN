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
        return (head == tail && head == NULL);
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

    static bool push_back(int n){
        LinkedList * p = new LinkedList(n);
        if(!p) return false;
        if(IsEmpty()){
            head = tail = p;
        }
        else{
            tail->next = p;
            p->prev = tail;
            tail = p;
        }
        return true;
    }

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

    static bool pop_back(){
        if (IsEmpty()) return false;
        LinkedList* temp = tail;
        if (head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete temp;
        return true;
    }

    static bool erase_element(int n){
    if (IsEmpty()) return false;
    LinkedList* current = head;
    while(current != NULL){
        if(current->element == n){
            if(current == head){
                head = current->next;
            } 
            if(current == tail){
                tail = current->prev;
            } 
            if(current->next != NULL){
                current->next->prev = current->prev;
            }
            if(current->prev != NULL){
                current->prev->next = current->next;
            }
            delete current;
            return true;
        }
        current = current->next;
    }
    return false;
}


    static bool delete_list(){
        if (IsEmpty()) return false;
        while(!IsEmpty()){
            pop_front();
        }
        return true;
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
    LinkedList::push_back(50);
    LinkedList::print();
    LinkedList::erase_element(10);
    LinkedList::print();
    LinkedList::delete_list();
    LinkedList::print();
    cout << LinkedList::get_size() << endl;
    return 0; 
}