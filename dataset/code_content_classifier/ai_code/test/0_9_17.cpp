#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int count_inversions(const vector<int>& a) {
    deque<int> d;
    int inversions = 0;

    for (int i = 0; i < a.size(); i++) {
        if (d.empty() || a[i] >= d.front()) {
            d.push_back(a[i]);
        } else {
            inversions++;
            d.push_front(a[i]);
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

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int result = count_inversions(a);
        cout << result << endl;
    }

    return 0;
}