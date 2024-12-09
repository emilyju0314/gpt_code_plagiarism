#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int q;
    cin >> q;

    vector<int> p(n);
    vector<int> inversions(n);

    for (int i = 0; i < n; i++) {
        inversions[i] = i - b[i];
    }

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int pos, x;
            cin >> pos >> x;
            pos--;

            inversions[pos] = pos - x;
            b[pos] = x;
        } else {
            int pos;
            cin >> pos;
            pos--;

            int val = inversions[pos] + 1;
            p[pos] = val;

            for (int j = pos + 1; j < n; j++) {
                if (inversions[j] == val) {
                    val++;
                }
            }

            cout << p[pos] << endl;
        }
    }

    return 0;
}