#include <iostream>

using namespace std;

int main() {
    int K, A, B;
    cin >> K >> A >> B;
    
    if (A % K == 0 || B % K == 0 || (A / K) != (B / K)) {
        cout << "OK" << endl;
    } else {
        cout << "NG" << endl;
    }

    return 0;
}