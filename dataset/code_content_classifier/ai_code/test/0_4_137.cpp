#include <iostream>
using namespace std;

bool isPossible(long long x, long long y) {
    if(x > y) {
        return false;
    }
    
    while(y > x) {
        if(y % 2 == 0) {
            y /= 2;
        } else {
            y++;
        }
        
        if(y == 1) {
            return false;
        }
    }
    
    return x == y;
}

int main() {
    long long x, y;
    cin >> x >> y;
    
    if(isPossible(x, y)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}