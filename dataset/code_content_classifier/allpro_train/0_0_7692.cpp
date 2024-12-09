#include <iostream>
using namespace std;

int main() {
    int N, K, X, Y;
    cin >> N >> K >> X >> Y;

    int total_fee = 0;
    if(N <= K) {
        total_fee = N * X;
    } else {
        total_fee = K * X + (N - K) * Y;
    }

    cout << total_fee << endl;

    return 0;
}