#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#define SIZE 200
using namespace std;

class DBStudent{
    class Student{
        string name;
        int age;
        char sex;

        public:
        Student(string name, int age, char sex) : name(name), age(age), sex(sex) {

        }
        string get_name() const{
            return name;
        }

        void print() const{
            cout << "name = " << name << " age = " << age << " sex = " << sex << endl;
        }
        
    };

    class Node {
        Student * sp = NULL;
        Node * next = NULL;
        bool IsExist = true;

        public:
        Node () = default;

        Node (Student * sp, Node * next) : sp(sp), next(next) {
        }

        ~Node () {
            delete sp;
        }

        bool ObjectIsExist() const{
            return IsExist;
        }

        Student * get_student() const{
            return sp;
        }

        Node * get_next() const{
            return next;
        }
    };

    Node * HashTable[SIZE];
    int total_number = 0;
    int real_number = 0;

    public:
    DBStudent (){
        for(int i = 0; i < SIZE; i++){
            HashTable[i] = NULL;
        }
    }

    ~DBStudent (){
    }

    static unsigned int hash_function(string & str){
        unsigned int hash = 5381;
        for (char c : str) {
            hash = ((hash << 5) + hash) + c;
        }
        return hash % SIZE;
    }

    bool insert(string name, int age, char sex){
        int key = hash_function(name);
        Student * new_st = new Student(name, age, sex);
        HashTable[key] = new Node(new_st, HashTable[key]);
        total_number++;
        real_number++;
        return true;
    }

    bool select_name(string str) const{
        int key = hash_function(str);
        Node * head = HashTable[key];
        Student * student;
        while(head){
            if(head -> ObjectIsExist()){
                student = head -> get_student();
                if ((head -> get_student()) -> get_name() == str){
                    student -> print();
                }
            }
            head = head -> get_next();
        }
        return true;
    }
};

int main()
{
    DBStudent db;
    db.insert("Ivan", 19, 'M');
    db.insert("Irina", 20, 'F');
    db.insert("Ivan", 21, 'M');
    db.insert("Irina", 22, 'F');
    db.insert("Bob", 23, 'M');
    db.select_name("Irina");

    return 0;
}