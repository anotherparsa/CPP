#include <iostream>

using namespace std;

class Node{
    public:
    int value;
    Node* next;

    Node(int value){
        this->value = value;
        this->next = nullptr;
    }
};

class Stack{
    private:
        Node* top;
        int height;
    public:
        Stack(){
            this->top = nullptr;
            this->height = 0;
        }

        bool is_stack_empty(){
            return this->height == 0;
        }

        void print_stack(){
            Node* temp = this->top;
            cout << "Stack Items" << endl;
            while (temp != nullptr){
                cout << temp->value << endl;
            }
        }

        
};

int main(){

}