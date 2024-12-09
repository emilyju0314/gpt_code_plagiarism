#include <iostream>

using namespace std;

bool canGetNumber(int x, int y) {
    if(x >= y) {
        return true;
    }
    
    if(x%2 == 0 && 3*x/2 >= y) {
        return true;
    }
    
    if(x%2 != 0 && x-1 >= y) {
        return true;
    }
    
    return false;
}

int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        
        if(canGetNumber(x, y)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}