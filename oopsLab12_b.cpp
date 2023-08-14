#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class Stack{
    int size,top;
    T *arr;

public:
    Stack(int s = 0):size(s),top(-1){
        arr = new T[size];
    }
    void push(T e){
        if(top == size-1){
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = e;
    }
    void pop(){
        if(top == -1){
            cout << "Stack underflow" << endl;
            return;
        }
        cout << "Popped " << arr[top--] << endl;
    }
    void display(){
        if(top == -1){
            cout << "Empty stack" << endl;
            return;
        }
        cout << "Stack : ";
        for(int i = 0; i <= top; i++){
        cout << arr[i] << " ";
        }
        cout << endl;
    }
    void Top(){
        if(top == -1){
            cout << "Empty Stack" << endl;
            return;
        }
        cout << arr[top] << endl;
    }
    virtual int runMenu() = 0;
    virtual ~Stack() {
        delete[] arr;
    }
};

template <typename T>
class StackMenu : public Stack<T> {
public:
    StackMenu(int s = 0) : Stack<T>(s) {}
    int runMenu() override {
        int menu;
        while (true) {
            cout << "1.Push\n2.Pop\n3.Display\n4.Top\n5.Change data type\n6.Exit program" << endl;
            cin >> menu;

            switch (menu) {
                case 1: {
                    T e;
                    cout << "Enter the element: ";
                    cin >> e;
                    this->push(e);
                    break;
                }
                case 2:
                    this->pop();
                    break;
                case 3:
                    this->display();
                    break;
                case 4:
                    this->Top();
                    break;
                case 5:
                    return 5;
                case 6:
                    return 6;
                default:
                    cout << "Invalid option" << endl;
            }
        }
    }
};



int main(){
    int dataType,menu,size,e,Break = 0;
    while(1){
        cout << "Choose datatype :" << endl;
        cout << "1.int\n2.float\n3.double" << endl;
        cin >> dataType;
        cout << "Enter the size:";
        cin >> size;
        if(dataType == 1){
            StackMenu<int> obj(size);
            Break = obj.runMenu();
        }
        else if(dataType == 2){
            StackMenu<float> obj(size);
            Break = obj.runMenu();
        }
        else if(dataType == 3){
            StackMenu<double> obj(size);
            Break = obj.runMenu();
        }
        else{
            cout << "Invalid data type " << endl;
        }
        if(Break == 6){
            break;
        }
    }
    return 0;
}