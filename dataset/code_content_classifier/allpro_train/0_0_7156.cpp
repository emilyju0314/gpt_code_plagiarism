#include <iostream>

using namespace std;

bool isComposite(int num) {
    if (num <= 1) {
        return false;
    }
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return true;
        }
    }
    
    return false;
}

int maxSummands(int n) {
    if (n <= 3) {
        return -1;
    }
    
    if (n % 4 == 0) {
        return n / 4;
    } else if (n % 4 == 1) {
        return (n - 9) / 4 + 1;
    } else if (n % 4 == 2) {
        return (n - 6) / 4 + 1;
    } else {
        return (n - 15) / 4 + 2;
    }
}

int main() {
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int ni;
        cin >> ni;
        
        if (isComposite(ni)) {
            cout << maxSummands(ni) << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}