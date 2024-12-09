#include <iostream>

using namespace std;

bool isLucky(int num) {
    while (num > 0) {
        int digit = num % 10;
        if (digit != 4 && digit != 7) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        if (n % i == 0 && isLucky(i)) {
            cout << "YES" << endl;
            return 0;
        }
    }
    
    cout << "NO" << endl;
    
    return 0;
}