#include <iostream>
using namespace std;

int main() {
    long long K, A, B;
    cin >> K >> A >> B;
    
    long long biscuits = 1;
    
    if (B - A <= 2) {
        cout << K + 1 << endl;
    } else {
        if (K <= A) {
            cout << biscuits + K << endl;
        } else {
            K -= A - 1;
            biscuits += A - 1;
            biscuits += (K / 2) * (B - A);
            if (K % 2 == 1) {
                biscuits++;
            }
            cout << biscuits << endl;
        }
    }
    
    return 0;
}