#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long A, B, C, K;
    cin >> A >> B >> C >> K;

    for (int i = 0; i < K; i++) {
        long long sum = A + B + C;
        A = sum - A;
        B = sum - B;
        C = sum - C;
    }

    if (abs(A - B) > 1e18) {
        cout << "Unfair" << endl;
    } else {
        cout << A - B << endl;
    }
    
    return 0;
}