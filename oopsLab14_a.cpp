#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> v;
    int menu,e,index;
    while(true){
        cout << "Menu\n1.size\n2.empty\n3.insert\n4.remove at index\n" <<
        "5.index of element\n6.display\n7.exit" << endl;
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
                v.erase(v.begin()+index);
                break;
            case 5:
            {
                cout << "Enter the elem to find its index :";
                cin >> e;
                auto it = find(v.begin(), v.end(), e);
                if (it != v.end()){
                    int index = it - v.begin();
                    cout << "Element found at index :" << index << endl;
                    break;
                }
                else{
                    cout << "Element not found" << endl;
                    break;
                }
            }
            case 6:{
                cout << "VECTOR: ";
                for(int i = 0; i < v.size(); i++){
                    cout << v[i] << " ";
                }
                cout << endl;
                break;
            }
            default:
                cout << "Program terminating" << endl;
                return 0;
        }
    }
}
