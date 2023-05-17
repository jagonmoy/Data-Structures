// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct stack {
    Node* head = NULL ;
    
    bool isEmpty(){
        if ( head == NULL) return true ;
        else return false;
    }
    
    void push(int x) {
        Node* newNode = new Node() ;
        newNode->data = x ;
        newNode->next = head;
        head = newNode ;
    }
    bool pop() {
        if(isEmpty()) return false ;
        Node* temp = head ;
        head = head -> next ;
        delete temp ;
        return true ;
    }
    void print() {
        Node* current = head ;
        if(current == NULL) cout << "Stack is empty!" << endl;
        while(current != NULL) {
            cout << current -> data << " " ;
            current = current -> next ;
        }
        cout << endl;
    }
    
};

int main() {
    // Write C++ code here
    stack sk ;
    while(true) {
        int x ;
        string op ;
        cout << "What is operation? " << endl;
        cin >> op ;
        if ( op == "push") {
            cout << "Enter your Number: " ; 
            cin >> x ;
            sk.push(x);
        }
        else if ( op == "pop") {
            bool result = sk.pop();
            if(result == false) cout << "Stack is already empty!"<< endl;
        }
        else if ( op == "print") {
            sk.print();
        }
    }

    return 0;
}