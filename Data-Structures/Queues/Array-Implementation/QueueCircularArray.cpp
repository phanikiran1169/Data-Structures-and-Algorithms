#include <iostream>

using namespace std;

template <typename T, int N>
class Queue{
private:
    T* queueFrame;
    int front;
    int back;

public:
    Queue(): queueFrame(new T[N]), front(-1), back(-1) {}

    ~Queue(){
        delete [] this->queueFrame;
    }

    bool isEmpty(){
        if(this->front ==  -1 and this->back == -1){
            return true;
        }
        return false;
    }

    bool isFull(){
        if(this->getLength() == N) return true;

        return false;
    }

    int getLength(){
        // cout << this->back << " " << this->front << endl;
        if(isEmpty()) return 0;
        if(this->back < this->front) return (this->back - this->front + 1 + N)%N;
        else return (this->back - this->front + 1)%N;
    }

    void enqueue(T data){
        if(this->isEmpty()){
            this->back = 0;
            this->front = 0;
        }

        else if(this->isFull()){
            cout << "Queue is full. Invalid Operation." << endl;
            return;
        }

        else{
            this->back = (this->back + 1)%N;
        }
        this->queueFrame[this->back] = data;
        return;
    }

    void dequeue(){
        if(this->isEmpty()){
            cout << "Queue is empty. Invalid Operation." << endl;
            return;
        }
        
        if(this->front == this->back){
            this->front = -1;
            this->back = -1;
        }

        else{
            this->front = (this->front + 1)%N;
        }

        return;
    }

    T top(){
        if(this->isEmpty()){
            throw "Invalid operation. Queue is empty";    
        }
        else 
            return this->queueFrame[front];
    }


};

int main(){
    Queue<int, 4> queue;
    queue.enqueue(1);
    queue.enqueue(3);
    cout << queue.getLength() << endl;

    return 0;
}