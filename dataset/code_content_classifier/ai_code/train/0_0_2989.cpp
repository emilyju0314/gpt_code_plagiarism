#include <iostream>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    int packsLeft = x;
    int distressedKids = 0;

    for (int i = 0; i < n; i++) {
        char op;
        int d;
        cin >> op >> d;

        if (op == '+') {
            packsLeft += d;
        } else {
            if (packsLeft >= d) {
                packsLeft -= d;
            } else {
                distressedKids++;
            }
        }
    }

    cout << packsLeft << " " << distressedKids << endl;

    return 0;
}