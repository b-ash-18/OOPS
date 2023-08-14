#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<ctime>
using namespace std;

int main(){
    srand(time(0));
    int size,sum = 0;
    vector<int> v;
    cout << "Enter the size of vector :";
    cin >> size;
    for(int i = 0; i < size; i++){
        v.push_back(rand()%10);
    }

    cout << "Vector before sort" << endl;
    for(int i = 0; i < size; i++){
        cout << v[i] << " ";
    }cout << endl;

    sort(v.begin(),v.end(),greater<int>());

    cout << "Vector after sort" << endl;
    for(int i = 0; i < size; i++){
        sum += v[i];
        cout << v[i] << " ";
    }cout << endl;
    cout << "Sum of vector is :" << sum << endl;
}