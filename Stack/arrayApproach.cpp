#include <iostream>
using namespace std;

struct stack {
    int top = -1 ;
    int arr[20];
    bool push(int x) {
        if( top+1 == 20) return false;
        top++;
        arr[top] = x ;
        return true ;
    }
    bool pop(){
        if(top < 0) return false;
        top-- ;
        return true ;
    }
    void print() {
        if(top == -1) cout << "Stack is Empty!" ;
        for ( int i = top ; i >= 0 ; i--) {
            cout << arr[i] << " " ;
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
            bool result = sk.push(x);
            if ( result == false) cout << "Stack Limit Exceeded!" << endl;;
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