#include <iostream>

using namespace std;

int main() {
    long long X, Y;
    cin >> X >> Y;
    
    // Find the smallest multiple of X that is not a multiple of Y
    for (long long i = 1; i <= 1000000000000000000; i++) {
        if (i % X == 0 && i % Y != 0) {
            cout << i << endl;
            return 0;
        }
    }
    
    // If no such integer exists, print -1
    cout << -1 << endl;
    
    return 0;
}