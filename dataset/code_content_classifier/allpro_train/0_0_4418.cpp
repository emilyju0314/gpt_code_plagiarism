#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> A(n+1, 0); // Initialize the sequence A with size n+1 and initial values of 0

    while (q--) {
        int type, s, t, x;
        cin >> type >> s >> t;

        if (type == 0) {
            cin >> x;
            for (int i = s; i <= t; i++) {
                A[i] += x;
            }
        } else if (type == 1) {
            int sum = 0;
            for (int i = s; i <= t; i++) {
                sum += A[i];
            }
            cout << sum << endl;
        }
    }

    return 0;
}