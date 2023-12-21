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

    int length(){
        return len;
    }

    void show(){
        cout << "------------------------------------------" << endl;
        if(this->head){
            Node<T> *temp = new Node<T>();
            temp = this->head;
            while(temp){
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
        else{
            cout << "The list is empty" << endl;
        }
        cout << "------------------------------------------" << endl;

        return;
    }


    void showDebug(){
        return;
    }

    void insertBeg(T data){
        Node<T> *temp = new Node<T>(data);
        if (this->head){
            temp->next = this->head;
        }
        else {
            temp->next = nullptr;
        }
        this->head = temp;

        return;
    }

};


int main(){

    SinglyLinkedList<int> list;
    list.show();
    list.insertBeg(2);
    list.insertBeg(3);
    list.show();
    return 0;
}