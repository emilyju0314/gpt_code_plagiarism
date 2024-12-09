#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    set<int> possible_k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int k = 1; k <= n; k++) {
        bool valid = true;
        for (int i = 1; i < n; i++) {
            if (a[i] - a[i-1] != a[(i-1) % k]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            possible_k.insert(k);
        }
    }

    cout << possible_k.size() << endl;
    for (int k : possible_k) {
        cout << k << " ";
    }
    cout << endl;

    return 0;
}