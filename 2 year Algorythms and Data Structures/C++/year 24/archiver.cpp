#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
Алгоритм Хаффмана статический. 2 прохода, сначала собираем статистику, потом строим дерево
Архиватор, Деревья (бинарные) на списках
Сначала собираем статистику по частоте символов
Берутся 2 символа с мин повторением и строится нижняя часть дерева
Потом соеденяем и будет их частота, и рядом следующая с минимума буква
И потом 0 1 расставляем в связах и получаем их коды

root это указатель, который указывает на начало дерева
Если узел будет значение -1 иначе название переменной, дальше идет указатель на left, потом на right
*/

class BTree {
    class Node {
        char element;
        int weight;
        Node* left;
        Node* right;
        public:
        Node (char element) : element(element),weight(0), left(NULL), right(NULL) {}
        ~Node() = default;

        char get_element() { return element; }
        void set_element(char e) { element = e; }
        int get_weight() { return weight; }
        void set_weight(int w) { weight = w; }
        Node* get_left() { return left; }
        void set_left(Node* p) { left = p; }
        Node* get_right() { return right; }
        void set_right(Node* p) { right = p; }


    };
    Node* root = NULL;

    public:
    BTree() = default;
    //~BTree() {}

    void CreateTree (){
        int row = 5;
        int Array[127][2] = {{'\0', 0}, {'A', 2}, {'B', 3}, 
                            {'C', 7}, {'D', 10}};
        while(row){
            
            row--;
        }
    }

};

int main()
{
    BTree b1;
    int parovoz = 8;

    return 0;
}