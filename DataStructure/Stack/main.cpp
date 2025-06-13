#include <iostream>
#include <climits>

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
            new_node->next = this->top;
            this->top = new_node;
            this->height++;
        }

        int pop_node(){
            if (this->top == 0){
                return INT_MIN;
            }
            int popped_value = this->top->value;
            Node* temp = this->top;
            this->top = this->top->next;
            delete temp;
            this->height--;
            return popped_value;
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
    cout << "Popped value " << mystack->pop_node() << endl;
    cout << "Popped value" << mystack->pop_node() << endl;
    mystack->print_stack();
    cout << "Popped value " << mystack->pop_node() << endl;
    cout << "Popped value" << mystack->pop_node() << endl;
    cout << "Popped value " << mystack->pop_node() << endl;
    mystack->print_stack();
    cout << "Popped value" << mystack->pop_node() << endl;
    mystack->print_stack();


}