#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class Calculator{
    T a,b;

public:
    Calculator(T n1, T n2):a(n1),b(n2){}
    T addition(){
        return a+b;
    }
    T subtraction(){
        return a-b;
    }
    T multiplication(){
        return a*b;
    }
    T division(){
        if(b == 0){
            cout << "Cannot divide by zero" << endl;
            return -999;
        }
        return a/b;
    }
    virtual int runMenu() = 0;
};

template <typename T>
class CalculatorMenu : public Calculator<T> {
public:
    CalculatorMenu(T n1, T n2) : Calculator<T>(n1,n2) {}
    int runMenu() override {
        int menu;
        while (true) {
            cout << "1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Change data type\n6.Exit program" << endl;
            cin >> menu;

            switch (menu) {
                case 1: {
                    cout << "Addition : " << this->addition() << endl;
                    break;
                }
                case 2:
                    cout << "Subtraction : " << this->subtraction() << endl;
                    break;
                case 3:
                    cout << "Mutiplication : " << this->multiplication() << endl;
                    break;
                case 4:
                    if(this->division() != -999)
                    cout << "Division : " << this->division() << endl;
                    else    cout << "Division by zero not allowed" << endl;
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
    int dataType,menu,Break = 0;
    while(1){
        cout << "Choose datatype :" << endl;
        cout << "1.int\n2.float\n3.double\n4.Exit program" << endl;
        cin >> dataType;
        if(dataType == 1){
            int n1,n2;
            cout << "Enter the numbers :";
            cin >> n1 >> n2;
            CalculatorMenu<int> obj(n1,n2);
            Break = obj.runMenu();
        }
        else if(dataType == 2){
            float n1,n2;
            cout << "Enter the numbers :";
            cin >> n1 >> n2;
            CalculatorMenu<float> obj(n1,n2);
            Break = obj.runMenu();
        }
        else if(dataType == 3){
            double n1,n2;
            cout << "Enter the numbers :";
            cin >> n1 >> n2;
            CalculatorMenu<double> obj(n1,n2);
            Break = obj.runMenu();
        }
        else if(dataType == 4){
            return 0;
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
