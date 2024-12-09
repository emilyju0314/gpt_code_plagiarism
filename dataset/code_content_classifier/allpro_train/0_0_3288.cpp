#include <iostream>
using namespace std;

int main() {
    long long N, A, B;
    cin >> N >> A >> B;

    for (int i = 1; i <= N; i++) {
        if (i % 2 == 1) {
            A = A - B;
        } else {
            B = A + B;
        }
    }

    cout << A << " " << B << endl;

    return 0;
}