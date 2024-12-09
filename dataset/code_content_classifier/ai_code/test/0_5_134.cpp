#include <iostream>
#include <vector>

using namespace std;

bool isBeautifulColoringPossible(vector<long long>& a, long long d) {
    for (int i = 1; i < a.size(); i++) {
        if (a[i] % d == 0 && a[i - 1] % d == 0) {
            return false;
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
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long d = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] % a[i - 1] != 0) {
                d = a[i - 1];
                break;
            }
        }

        if (d == 0) {
            cout << "0" << endl;
        } else {
            if (isBeautifulColoringPossible(a, d)) {
                cout << d << endl;
            } else {
                cout << "0" << endl;
            }
        }
    }

    return 0;
}