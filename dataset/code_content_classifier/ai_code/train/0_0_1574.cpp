#include <iostream>

using namespace std;

bool isPossibleTower(long long x) {
    if (x < 15) return false;
    if (x % 14 >= 1 && x % 14 <= 6) return true;
    return false;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long x;
        cin >> x;
        
        if (isPossibleTower(x)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}