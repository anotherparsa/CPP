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

        void print_list(){
            Node* temp = this->head;

            while(temp != nullptr){
                cout << temp->value << " ";
                temp = temp->next;
            }

            cout << endl;
        }

        Node* get_node_by_index(int index){
            if(this->is_list_empty()){
                return nullptr;
            }else if ((index < 0 ) || (index >= this->length)){
                return nullptr;
            }else{
                Node* temp = this->head;

                for (int i = 0 ; i < index ; i++){
                    temp = temp->next;
                }
    
                return temp;
            }
        }

        bool append_node(int value){
            Node* new_node = new Node(value);

            if(new_node != nullptr){
                if(this->is_list_empty()){
                    this->head = new_node;
                    this->tail = new_node;
                }else{
                    this->tail->next = new_node;
                    this->tail = new_node;
                }
    
                this->length++;
                return true;
            }else{
                return false;
            }
        }

        bool prepend_node(int value){
            Node* new_node = new Node(value);

            if(new_node != nullptr){
                if(this->is_list_empty()){
                    this->head = new_node;
                    this->tail = new_node;
                }else{
                    new_node->next = this->head;
                    this->head = new_node;
                }
    
                this->length++;
                return true;
            }else{
                return false;
            }

        }

        bool insert_node(int index, int value){
            if ((index < 0 ) || (index > this->length)){
                return false;
            }else{
                if (index == 0){
                    this->prepend_node(value);
                    return true;
                }else if (index == this->length){
                    this->append_node(value);
                    return true;
                }else{
                    Node* new_node = new Node(value);
                    
                    if(new_node != nullptr){
                        Node* previous = this->head;

                        for (int i = 0 ; i < index - 1 ; i++){
                            previous = previous->next;
                        }
    
                        new_node->next = previous->next;
                        previous->next = new_node;
                        this->length++;
                        return true;
                    }else{
                        return false;
                    }
                }
            }
        }

        bool delete_last_node(){
            if (this->is_list_empty()){
                return false;
            }else{
                Node* temp = this->head;
                if (this->length == 1){
                    this->head = nullptr;
                    this->tail = nullptr;
                }else{
                    Node* previous = nullptr;

                    while(temp->next != nullptr){
                        previous = temp;
                        temp = temp->next;
                    }

                    previous->next = nullptr;
                    this->tail = previous;
                }

                delete temp;
                this->length--;
                return true;
            }
        }

        bool delete_first_node(){
            if(this->is_list_empty()){
                return false;
            }else{
                Node* temp = this->head;

                if(this->length == 1){
                    this->head = nullptr;
                    this->tail = nullptr;
                }else{
                    this->head = this->head->next;
                }

                this->length--;
                delete temp;
                return true;
            }
        }

        bool delete_node(int index){
            if(this->is_list_empty()){
                return false;
            }else{
                if ((index < 0) || (index >= this->length)){
                    return false;
                }else{
                    if (index == 0){
                        this->delete_first_node();
                        return true;
                    }else if (index == this->length - 1){
                        this->delete_last_node();
                        return true;
                    }else{
                        Node* temp = this->head;
                            Node* previous = this->head;

                            for (int i = 0 ; i < index ; i++){
                                previous = temp;
                                temp = temp->next;
                            }

                            previous->next = temp->next;
                            delete temp;
                            this->length--;
                            return true;
                    }
                }
            }
        }
};


int main(){
    LinkedList* SLL = new LinkedList();
    SLL->append_node(1);
    SLL->append_node(2);
    SLL->append_node(3);
    SLL->insert_node(0,0);
    SLL->prepend_node(-1);
    SLL->prepend_node(-2);
    SLL->prepend_node(-3);
    SLL->print_list();
    SLL->append_node(22);
    SLL->append_node(33);
    SLL->print_list();
    SLL->delete_last_node();
    SLL->delete_last_node();
    SLL->print_list();
    SLL->delete_node(3);
    SLL->print_list();
}