#include <iostream>
#include <string>

using namespace std;

int lastRemainingCard(int N, int A, int B, string D_A, string D_B) {
    bool isClockwise = (D_A == "right");
    int remainingCards = N;

    while (remainingCards > 1) {
        int distance = abs(A - B);
        if (distance % 2 == 0) {
            remainingCards = (remainingCards + 1) / 2;
            if (isClockwise) {
                A = (A + remainingCards) % N;
                B = (B + remainingCards) % N;
            } else {
                A = (A - remainingCards + N) % N;
                B = (B - remainingCards + N) % N;
            }
        } else {
            remainingCards /= 2;
            isClockwise = !isClockwise;
            if (isClockwise) {
                A = (A + remainingCards) % N;
                B = (B + remainingCards) % N;
            } else {
                A = (A - remainingCards + N) % N;
                B = (B - remainingCards + N) % N;
            }
        }
    }

    return A;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, A, B;
        string D_A, D_B;

        cin >> N >> A >> B >> D_A >> D_B;

        cout << lastRemainingCard(N, A, B, D_A, D_B) << endl;
    }

    return 0;
}