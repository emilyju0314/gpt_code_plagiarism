#include <iostream>

using namespace std;

int main() {
    long long N, A, B;
    cin >> N >> A >> B;

    long long rounds = 0;

    while (A != B) {
        rounds++;
        A = (A + 1) / 2;
        B = (B + 1) / 2;
        N /= 2;
    }

    cout << rounds << endl;

    return 0;
}