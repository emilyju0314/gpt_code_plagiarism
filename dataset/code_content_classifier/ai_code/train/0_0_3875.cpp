#include <iostream>

using namespace std;

int main() {
    int X, Y;
    cin >> X >> Y;
    
    int amount = 0;
    
    if(X == 1) {
        amount = 100000;
    } else if(X == 2) {
        amount = 200000;
    } else if(X == 3) {
        amount = 300000;
    }
    
    if(Y == 1) {
        amount += 100000;
    } else if(Y == 2) {
        amount += 200000;
    } else if(Y == 3) {
        amount += 300000;
    }
    
    if(X == 1 && Y == 1) {
        amount += 400000;
    }
    
    cout << amount << endl;
    
    return 0;
}