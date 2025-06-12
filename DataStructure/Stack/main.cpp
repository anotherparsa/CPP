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
};

int main(){

}