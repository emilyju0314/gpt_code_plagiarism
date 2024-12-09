#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    deque<int> dq;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        dq.push_back(num);
    }

    for (int i = 0; i < q; i++) {
        long long m;
        cin >> m;

        if (m <= n) {
            cout << dq[m - 1] << " " << dq[m] << "\n";
        } else {
            cout << dq.back() << " " << dq.front() << "\n";
        }
    }

    return 0;
}