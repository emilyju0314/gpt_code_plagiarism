#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int x;
    cin >> x;
    for(int i=0; i < x; i++){
        int value;
        cout << "Case " << i+1 << ":" << endl;
        cin >> value;
        for(int j=0; j < 10; j++){
            value = pow(value, 2);
            value = value/100%10000;
            cout << value << endl;
        }
    }
}