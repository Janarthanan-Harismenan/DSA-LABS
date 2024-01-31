#include <iostream>
#include <chrono>

using namespace std;

// Define a Node struct for the linked list
struct Node {
    int data;
    Node* next;
};

// Define the Stack class
class Stack {
private:
    Node* head; // Pointer to the first Node in the list
public:
    Stack() {
        head = nullptr; // Initialize the head pointer to null
    }

    // Push a value onto the Stack
    void push(int value) {
        Node* newNode = new Node; // Create a new Node
        newNode->data = value; // Set its data value to the input value
        newNode->next = head; // Set the new Node's next pointer to the current head
        head = newNode; // Set the head to the new Node
    }

    // Pop a value off the Stack
    int pop() {
        if (isEmpty()) {
            cerr << "Stack Underflow\n"; // If the Stack is empty, print an error message and return -1
            return -1;
        }
        int value = head->data; // Get the data value of the head Node
        Node* temp = head; // Create a temporary pointer to the head Node
        head = head->next; // Set the head to the next Node in the list
        delete temp; // Delete the old head Node
        return value;
    }

    // Check if the Stack is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Get the value at the top of the Stack
    int top() {
        if (isEmpty()) {
            cerr << "Stack is empty\n"; // If the Stack is empty, print an error message and return -1
            return -1;
        }
        return head->data;
    }

    // Print the elements of the Stack
    void display() {
        Node* temp = head; // Create a temporary pointer to the head Node
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s; // Create a new stack object

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
