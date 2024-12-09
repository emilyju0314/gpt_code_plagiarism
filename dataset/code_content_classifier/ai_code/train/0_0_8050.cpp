#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N;

    vector<int> c(N);
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }

    cin >> Q;

    bool impossible = false;
    for (int i = 0; i < Q; i++) {
        int t, x, d;
        cin >> t >> x >> d;

        if (t == 1) {
            if (d > c[x-1]) {
                cout << i+1 << endl;
                impossible = true;
                break;
            }
        } else {
            if (d > c[x-1]) {
                cout << i+1 << endl;
                impossible = true;
                break;
            }
        }
    }

    if (!impossible) {
        cout << 0 << endl;
    }

    return 0;
}