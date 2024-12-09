#include <iostream>
using namespace std;

bool canTurnInto(long long x, long long y) {
    if(x > y) return false;
    if(x == y) return true;
    
    if(y % 2 != 0) {
        return false;
    } else {
        return canTurnInto(x, y / 2);
    }
}

int main() {
    long long x, y;
    cin >> x >> y;
    
    if(canTurnInto(x, y)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}