#include <iostream>
#include <chrono>
using namespace std;

class Stack {
private:
    int top;
    int *arr;
    int size;
public:
    Stack(int size) {
        top = -1;
        this->size = size;
        arr = new int[size];
    }
    void push(int x) {
        if (top >= size - 1) {
            cout << "Stack Overflow" << endl;
        }
        else {
            top++;
            arr[top] = x;
        }
    }
    int pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else {
            int x = arr[top];
            top--;
            return x;
        }
    }
    int isEmpty() {
        return (top < 0);
    }
    int isFull() {
        return (top >= size - 1);
    }
    int stackTop() {
        if (top < 0) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        else {
            return arr[top];
        }
    }
    void display() {
        if (top < 0) {
            cout << "Stack is Empty" << endl;
        }
        else {
            cout << "Stack Elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {

    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack s(size);

    auto startTime = chrono::high_resolution_clock::now();
    
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);

    s.display();

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    s.display();

    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);

    s.display();

    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

    cout << "Time taken : " << duration << " ms \n" ;
    
    return 0;
}
