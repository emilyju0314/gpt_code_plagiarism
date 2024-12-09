#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;

        bool found = false;
        for (int j = 0; j < n; j++) {
            if (A[j] == k) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }

    return 0;
}