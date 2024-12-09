#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int idx;
            cin >> idx;
            cout << sequence[idx - 1] << endl;
        } else if (type == 2) {
            int a, b, x;
            cin >> a >> b >> x;
            for (int j = a - 1; j <= b - 1; j++) {
                sequence[j] = x;
            }
        } else if (type == 3) {
            int a, b, x;
            cin >> a >> b >> x;

            bool hasBadNumber = false;
            do {
                hasBadNumber = false;
                for (int j = a - 1; j <= b - 1; j++) {
                    sequence[j] += x;
                    if (sequence[j] % 42 == 0) {
                        hasBadNumber = true;
                        break;
                    }
                }
            } while (hasBadNumber);
        }
    }

    return 0;
}