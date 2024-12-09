#include <iostream>
#include <vector>

using namespace std;

bool canEraseSequence(vector<int>& a) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] % (i + 1) != 0) {
            return true;
        }
    }
    return false;
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

        if (canEraseSequence(a)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}