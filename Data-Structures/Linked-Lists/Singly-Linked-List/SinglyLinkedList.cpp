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
            cout << "Length : " << this->length() << endl;
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
        if (this->head){
            temp->next = this->head;
        }
        else {
            temp->next = nullptr;
        }
        this->head = temp;
        this->len++;

        return;
    }

};


int main(){

    SinglyLinkedList<int> list;
    list.insertBeg(2);
    list.insertBeg(3);
    list.showDebug();
    return 0;
}