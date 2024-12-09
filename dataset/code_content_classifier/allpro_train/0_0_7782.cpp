#include<iostream>
using namespace std;

bool isValid(int r, int c){
    if((r*c)%2 != 0){
        return false;
    } else {
        return true;
    }
}

int main(){
    int r, c;
    while(cin >> r >> c){
        if(r == 0 && c == 0){
            break;
        }
        if(isValid(r, c)){
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}