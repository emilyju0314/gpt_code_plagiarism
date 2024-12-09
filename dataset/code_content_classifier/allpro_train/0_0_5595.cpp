#include <iostream>
using namespace std;

int main() {
    long long A, B;
    cin >> A >> B;

    long long X = 0, Y = 0;

    for (int bit = 63; bit >= 0; --bit) {
        if ((A & (1LL << bit)) && (B & (1LL << bit))) {
            cout << -1 << endl;
            return 0;
        } else if ((A & (1LL << bit)) || (B & (1LL << bit))) {
            if (A & (1LL << bit)) {
                Y |= (1LL << bit);
            } else {
                X |= (1LL << bit);
            }
        }
    }

    cout << X << " " << Y << endl;

    return 0;
}