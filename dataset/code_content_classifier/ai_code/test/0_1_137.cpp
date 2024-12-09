#include <iostream>
#include <string>
using namespace std;

long long reverseBinary(long long num) {
    string binary = "";
    while (num > 0) {
        binary += to_string(num % 2);
        num /= 2;
    }
    reverse(binary.begin(), binary.end());
    
    return stoll(binary, nullptr, 2);
}

bool canReach(long long x, long long y) {
    while (y >= x) {
        if (y == x) {
            return true;
        }
        if (y % 2 == 0) {
            y /= 2;
        } else if (y % 10 == 1) {
            y = (y - 1) / 10;
        } else {
            return false;
        }
    }
    return false;
}

int main() {
    long long x, y;
    cin >> x >> y;
    
    if (canReach(x, y)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}