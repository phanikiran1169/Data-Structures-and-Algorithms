#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T, int N>
class Stack{

private:
    T *stackFrame;
    int length;
    int multiplier;

public:
    Stack(): stackFrame(new T[N]), length(0), multiplier(1) {}
    
    ~Stack(){
        delete [] this->stackFrame;
        // cout << "Stack Destructor" << endl;
    }

    int getLength(){
        return this->length;
    }

    bool isFull(){
        if(this->getLength() == N) return true;
        return false;
    }

    bool isEmpty(){
        if (this->getLength() < 1) return true;
        return false; 
    }

    void push(T data){
        if(this->isFull()){
            this->resize();
        }
        stackFrame[++(this->length)] = data;
        
        return;
    }

    void pop(){
        if(this->getLength() > 0){
            this->length--;
        }
        else{
            throw "Stack is empty. Invalid operation\n";
        }        

        return;
    }
    
    T top(){
        if(this->getLength() > 0){
            return stackFrame[this->getLength()];
        }
        else{
            throw "Stack is empty. Invalid operation\n";
        }
    }

    void show(){
        cout << "------------------------------------------" << endl; 
        for(int i = this->getLength()-1; i >=0; i--){
            cout << "| " << this->stackFrame[i] << " |" << endl;
        }
        cout << "------------------------------------------" << endl;
        return;
    }

private:    
    void resize(){
        cout << "Resizing" << endl;
        this->multiplier *= 2;

        T* tempFrame = new T[this->multiplier * N];
        for(int i = 0; i < this->getLength(); i++){
            tempFrame[i] = this->stackFrame[i];
        }
        delete [] this->stackFrame;
        this->stackFrame = tempFrame;

        return;
    }

};

int main(){
    Stack<int, 5> stack;
    
    try{
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(1);
        stack.push(8);
        cout << stack.isFull() << endl;
        stack.push(9);
        cout << stack.top() << endl;
        // stack.pop();
        cout << stack.isFull() << endl;
        stack.show();
    }
    catch(const char* textException){
        cout << "Exception " << textException << endl;
    }

    return 0;
}