#include <iostream>
#include <deque>

using namespace std;

int countInversions(deque<int>& dq, int val) {
    int inversions = 0;

    for (int i = 0; i < dq.size(); i++) {
        if (val > dq[i]) {
            inversions++;
        }
    }

    return inversions;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        deque<int> dq;
        long long inversions = 0;

        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;

            int inv1 = countInversions(dq, val);
            int inv2 = countInversions(dq, -val);

            if (inv1 <= inv2) {
                dq.push_back(val);
                inversions += inv1;
            } else {
                dq.push_front(val);
                inversions += inv2;
            }
        }

        cout << inversions << endl;
    }

    return 0;
}