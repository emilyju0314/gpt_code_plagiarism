#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_possible(vector<int>& b) {
    vector<int> a;
    for (int i = 0; i < b.size(); i++) {
        a.push_back(b[i]);
        sort(a.begin(), a.end());
        if (a[(i+1)/2] != b[i]) {
            return false; // Check if the median of a is equal to b[i]
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        if (is_possible(b)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}