#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    int menu,e,index;
    while(true){
        cout << "Menu\n1.size\n2.empty\n3.insert\n4.remove at index\n" <<
        "5.index of elemen\nt6.exit" << endl;
        cin >> menu;
        switch(menu){
            case 1:
                cout << "Size :" << v.size() << endl;
                break;
            case 2:
                if(v.size() == 0){
                    cout << "Empty vector" << endl;
                }
                else{
                    cout << "Not empty" << endl;
                }
                break;
            case 3:
                cout << "Enter an element :";
                cin >> e;
                v.push_back(e);
                break;
            case 4:
                cout << "Enter the index to remove :";
                cin >> index;
                v;
                break;
            case 5:
                cout << "Enter the elem to find its index :";
                cin >> e;

                cout << "Element found at index :" << endl;
                break;
            default:
                cout << "Program terminating" << endl;
                return 0;
        }
    }
}