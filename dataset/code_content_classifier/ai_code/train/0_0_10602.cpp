#include <iostream>

using namespace std;

int main() {
    int n, p, k;
    cin >> n >> p >> k;

    if (p - k > 1) {
        cout << "<< ";
    }

    for (int i = max(1, p - k); i <= min(n, p + k); i++) {
        if (i == p) {
            cout << "(" << i << ") ";
        } else {
            cout << i << " ";
        }
    }

    if (p + k < n) {
        cout << ">>";
    }

    cout << endl;

    return 0;
}