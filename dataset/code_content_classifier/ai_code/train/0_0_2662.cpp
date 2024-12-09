#include <iostream>

using namespace std;

int main() {
    long long A, B, K;
    cin >> A >> B >> K;
    
    while (K > 0) {
        if (A > 0) {
            A--;
        } else if (B > 0) {
            B--;
        }
        K--;
    }
    
    cout << A << " " << B << endl;
    
    return 0;
}