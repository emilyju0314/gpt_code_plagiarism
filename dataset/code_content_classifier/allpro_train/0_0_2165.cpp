#include <iostream>

using namespace std;

int main() {
    long long A, B;
    int N;
    cin >> A >> B >> N;

    long long targetA = A;
    long long targetDiff = B;

    for (int i = 1; i <= N; i++) {
        long long newA = (A + i - 1) / i;
        long long newB = (B + i - 1) / i;

        long long diff = abs(newA * i - A) + abs(newB * i - B);

        if (diff < targetDiff) {
            targetA = newA * i;
            targetDiff = diff;
        }
    }

    cout << targetDiff << endl;

    return 0;
}