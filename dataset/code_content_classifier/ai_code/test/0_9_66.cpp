#include <iostream>
using namespace std;

int lastRemaining(int n, int a, int b, string dA, string dB) {
    bool isLeftToRight = (dA == "right");
    bool isRightToLeft = (dB == "left");

    bool isReverse = (a < b && (a % 2) == 1 && (b % 2) == 0) || (b < a && (b % 2) == 1 && (a % 2) == 0);

    if (isReverse) {
        int diff = abs(a - b);
        int remaining = (n - diff) % n;
        if (remaining == 0) remaining = n;
        return remaining - 1;
    } else {
        int diff = (a < b) ? b - a : a - b;
        int remaining = n - diff;
        if (isLeftToRight) {
            return (a + remaining) % n;
        } else {
            return (a - remaining) % n;
        }
    }
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N, A, B;
        string D_A, D_B;
        cin >> N >> A >> B >> D_A >> D_B;

        int result = lastRemaining(N, A, B, D_A, D_B);
        cout << result << endl;
    }

    return 0;
}