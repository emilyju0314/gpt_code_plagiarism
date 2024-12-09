#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int A = 0;
    int B = 1; // Initialize B to 1, so that division by 1 doesn't affect the result

    for (int i = 0; i < N; i++) {
        int q, x;
        cin >> q >> x;

        if (q == 1) {
            B *= x;
        } else if (q == 2) {
            A += x;
            B *= 1;
        } else {
            A -= x;
            B *= 1;
        }
    }

    cout << A << " " << B << endl;

    return 0;
}