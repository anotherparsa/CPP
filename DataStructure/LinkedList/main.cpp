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

class LinkedList{
    private:
        Node* head;
        Node* tail;
        int length;
    
    public:
        LinkedList(){
            this->head = nullptr;
            this->tail = nullptr;
            this->length = 0;
        }

        bool is_list_empty(){
            return (this->length == 0);
        }

        Node* return_head(){
            return this->head;
        }

        Node* return_tail(){
            return this->tail;
        }

        int return_length(){
            return this->length;
        }

        bool append_node(int value){
            Node* new_node = new Node(value);

            if(this->is_list_empty()){
                this->head = new_node;
                this->tail = new_node;
            }else{
                this->tail->next = new_node;
                this->tail = new_node;
            }

            this->length++;
        }

        bool prepend_node(int value){
            Node* new_node = new Node(value);

            if(this->is_list_empty()){
                this->head = new_node;
                this->tail = new_node;
            }else{
                new_node->next = this->head;
                this->head = new_node;
            }

            this->length++;
        }

        bool insert_node(int index, int value){
            if(this->is_list_empty()){
                return false;
            }else if ((index <= 0 ) && (index > this->length)){
                return false;
            }else{
                if (index == 0){
                    this->prepend_node(value);
                }else if (index == this->length){
                    this->append_node(value);
                }else{
                    Node* new_node = new Node(value);
                    Node* previous = this->head;

                    for (int i = 0 ; i < index - 1 ; i++){
                        previous = previous->next;
                    }

                    new_node->next = previous->next;
                    previous->next = new_node;
                    this->length++;
                }
            }
        }

        void print_list(){
            Node* temp = this->head;

            while(temp != nullptr){
                cout << temp->value << " ";
                temp = temp->next;
            }

            cout << endl;
        }
};