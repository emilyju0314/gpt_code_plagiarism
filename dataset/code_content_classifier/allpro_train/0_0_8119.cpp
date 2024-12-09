#include <iostream>

using namespace std;

int main() {
    int A, B, K;
    cin >> A >> B >> K;

    for (int i = 0; i < K; i++) {
        if (i % 2 == 0) {
            if (A % 2 == 1) {
                A--;
            }
            int half = A / 2;
            B += half;
            A -= half;
        } else {
            if (B % 2 == 1) {
                B--;
            }
            int half = B / 2;
            A += half;
            B -= half;
        }
    }

    cout << A << " " << B << endl;

    return 0;
}