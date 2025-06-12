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

        void print_stack(){
            Node* temp = this->top;
            cout << "Stack Items" << endl;
            while (temp != nullptr){
                cout << temp->value << endl;
                temp = temp->next;
            }
            cout << "Height : " << this->height << endl;
        }

        void push_node(int value){
            Node* new_node = new Node(value);
            if (this->height == 0){
                this->top = new_node;
            }else{
                new_node->next = this->top;
                this->top = new_node;
            }
            this->height++;
        }

        
};

int main(){

    Stack* mystack = new Stack();
    mystack->print_stack();
    mystack->push_node(1);
    mystack->push_node(2);
    mystack->push_node(3);
    mystack->push_node(4);
    mystack->print_stack();

}