#include <iostream>

using namespace std;

template<typename T>
class Node{
public:
    Node<T> *next;
    T data;

    Node() : next(nullptr), data() {}
    Node(T data) : next(nullptr), data(data) {}

};

template<typename T>
class SinglyLinkedList{
public:

    SinglyLinkedList() : head(nullptr), tail(nullptr), len(0) {}

private:
    Node<T> *head;
    Node<T> *tail;
    int len;

public:

    bool isEmpty(){
        if (len == 0) return true;
        else return false;
    }

    int getLength(){
        return len;
    }

    void show(){
        cout << "--------------- NORMAL VIEW -------------" << endl;
        if(this->head){
            Node<T> *temp = new Node<T>();
            temp = this->head;
            while(temp){
                if(temp == this->head){
                    cout << temp->data;
                }
                else{
                    cout << " -> " << temp->data;
                }
                
                temp = temp->next;
            }
        }
        else{
            cout << "The list is empty";
        }
        cout << endl << "------------------------------------------" << endl;

        return;
    }


    void showDebug(){
        cout << "------------- DEBUG VIEW ----------------" << endl;
        if(this->head){
            Node<T> *temp = new Node<T>();
            int position = 0;
            temp = this->head;
            cout << "Length : " << this->getLength() << endl;
            while(temp){
                cout << "Position : " << position << " >> ";
                if(temp == this->head){
                    cout << "| Head Address: " << temp << " | Data: " << temp->data << " | Next Address: ";
                    if(temp->next == nullptr) cout << "NULL |";
                    else cout << temp->next << " |";
                }
                else{
                    cout << "| Current Address: " << temp << " | Data: " << temp->data << " | Next Address: ";
                    if(temp->next == nullptr) cout << "NULL |";
                    else cout << temp->next << " |";
                }
                cout << endl;
                position++;
                temp = temp->next;
            }
        }
        else{
            cout << "The list is empty" << endl;
        }
        cout << "------------------------------------------" << endl;       
        return;
    }

    void insertBeg(T data){
        Node<T> *temp = new Node<T>(data);
        temp->next = this->head;
        this->head = temp;
        this->len++;

        return;
    }

    void insertEnd(T data){
        Node<T> *temp = new Node<T>(data);
        if(this->head){
            Node<T> *curr = new Node<T>();
            curr = this->head;
            while(curr->next){
                curr = curr->next;
            }
            curr->next = temp;
            temp->next = nullptr;
        }
        else{
            this->head = temp;
            temp->next = nullptr;
        }

        this->len++;
        return;
    }

    void insertAtPos(int position, T data){
        if((position < 0) or (position > this->getLength())) {
            cout << "Incorrect operation. Position out of bounds" << endl;
        }
        else{
            Node<T> *curr = this->head;
            if(curr){
                Node<T> *prev = nullptr;
                for(int i = 0; i < position; i++){
                    prev = curr;
                    curr = curr->next;
                }
                Node<T> *temp = new Node<T>(data);
                temp->next = curr;
                if(position != 0){
                    prev->next = temp;
                }
                else{
                    this->head = temp;
                }

            }
            else{
                this->head = new Node<T>(data);
                this->head->next = nullptr;
            }
            this->len++;
        }
        return;
    }

    bool search(T data){
        Node<T> *curr = this->head;
        if(curr){
            while(curr){
                if(curr->data == data) return true;
                curr = curr->next;
            }
            return false;
        }
        else{
            return false;
        }
    }

};


int main(){

    SinglyLinkedList<int> list;
    list.insertBeg(2);
    list.insertBeg(3);
    list.insertEnd(4);
    list.insertEnd(5);
    list.showDebug();
    list.insertAtPos(4, 6);
    list.insertAtPos(0, 7);
    list.insertAtPos(7, 7);
    list.showDebug();
    cout << list.search(4) << endl;
    cout << list.search(9) << endl;
    return 0;
}