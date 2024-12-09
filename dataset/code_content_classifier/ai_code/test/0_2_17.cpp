#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        deque<int> dq;
        int max_val = a[n - 1];
        dq.push_back(a[n - 1]);

        for (int i = n - 2; i >= 0; i--) {
            if (a[i] < max_val) {
                if (dq.front() < a[i]) {
                    dq.push_back(a[i]);
                } else {
                    dq.push_front(a[i]);
                }
            } else {
                dq.push_front(a[i]);
                max_val = a[i];
            }
        }

        int inversions = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (dq[i] > dq[j]) {
                    inversions++;
                }
            }
        }

        cout << inversions << endl;
    }

    return 0;
}