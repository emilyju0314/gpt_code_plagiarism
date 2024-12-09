#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int diff = 0;
    int turn = 1;

    while (!a.empty() || !b.empty()) {
        if (turn == 1) {
            if (!b.empty() && (a.empty() || b.back() > a.back())) {
                b.pop_back();
            } else {
                diff += a.back();
                a.pop_back();
            }
            turn = 2;
        } else {
            if (!a.empty() && (b.empty() || a.back() > b.back())) {
                a.pop_back();
            } else {
                diff -= b.back();
                b.pop_back();
            }
            turn = 1;
        }
    }

    cout << diff << endl;

    return 0;
}