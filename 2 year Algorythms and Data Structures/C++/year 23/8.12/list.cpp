#include <iostream>
using namespace std;

class List{
        class Node{
            int element;
            Node * next = NULL;
            Node * prev = NULL;
            
            public:
                Node(int element) : element(element) {}
                void set_element(int n){
                    element = n;
                }
                void set_next(Node * p){
                    next = p;
                }
                void set_prev(Node * p){
                    prev = p;
                }
                int get_element(){
                    return element;
                }
                Node * get_next(){
                    return next;
                }
                Node * get_prev(){
                    return prev;
                }
        };    
        int counter = 0;
        Node * head = NULL;
        Node * tail = NULL;
        
        public:
        List() = default;
        // Конструктор копирования
        List(const List& other) {
            Node* temp = other.head;
            while (temp != NULL) {
                this->push_back(temp->get_element());
                temp = temp->get_next();
            }
        }

        // Деструктор
        ~List() {
            while (head != NULL) {
                Node* temp = head;
                head = head->get_next();
                delete temp;
            }
        }
        
        // Оператор копирующего присваивания
        List& operator=(const List& other) {
            if (this != &other) {
                while (head != NULL) {
                    Node* temp = head;
                    head = head->get_next();
                    delete temp;
                }
                Node* temp = other.head;
                while (temp != NULL) {
                    this->push_back(temp->get_element());
                    temp = temp->get_next();
                }
            }
            return *this;
        }
        
        void print_front() const {
            if(counter == 0) {
                cout<<"List is empty: \n";
                return ;
            }
            Node * p = head;
            cout<<"front => ";
            while(p){
                cout<<p->get_element()<<" -> ";
                p = p->get_next();                
            }
            cout<<endl;
        }

        void print_back() const {
            if(counter == 0) {
                cout<<"List is empty: \n";
                return ;
            }
            Node * p = tail;
            cout<<"back => ";
            while(p){
                cout<<p->get_element()<<" -> ";
                p = p->get_prev();                
            }
            cout<<endl;
        }
        
        bool push_front(int n){
            Node * p = new Node(n);   
            if(!p) return false;
            if(counter == 0) {
                head = tail = p;
            }
            else {
                p->set_next(head);
                head->set_prev(p);
                head = p;
            }
            counter++;
            return true;
        }

        bool push_back(int n){
            Node * p = new Node(n);
            if(!p) return false;
            if(counter == 0) {
                head = tail = p;
            }
            else{
                p->set_prev(tail);
                tail->set_next(p);
                tail = p; 
            }
            counter++;
            return true;
        }

        bool pop_front(){
            if(counter == 0) return false;
            Node * p = head;
            if(counter == 1) head = tail = NULL;
            else{
                head = p->get_next();
                head->set_prev(NULL);
            }
            counter--;
            delete p;
            return true;
        }

        bool pop_back(){
            if(counter == 0) return false;
            Node * p = tail;
            if(counter == 1) head = tail = NULL;
            else{
                tail = p->get_prev();
                tail->set_next(NULL);
            }
            counter--;
            delete p;
            return true;
        }
};

int main()
{
    List l1, l2;
    l1.push_front(10);
    l1.push_front(20);
    l1.push_front(30);
    l1.push_back(40);
    l1.pop_front();
    l1.print_front(); // 20 10 40 
    l1.pop_back();
    l1.print_front(); // 20 10
    l2 = l1;
    l1.push_front(50);
    l1.print_front(); // 50 20 10
    l2.print_front(); // 20 10
    return 0;
}
