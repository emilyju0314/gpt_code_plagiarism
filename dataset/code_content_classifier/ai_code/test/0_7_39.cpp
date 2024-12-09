#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> permutation(n);
    set<int> s;

    for (int i = 1; i <= n; i++) {
        vector<int> query(n);
        for (int j = 0; j < n; j++) {
            query[j] = j + 1;
        }

        cout << "? ";
        for (int j = 0; j < n; j++) {
            cout << query[j] << " ";
        }
        cout << endl;

        int k;
        cin >> k;

        if (s.count(k)) {
            permutation[k - 1] = i;
        } else {
            s.insert(k);
        }
    }

    cout << "! ";
    for (int i = 0; i < n; i++) {
        cout << permutation[i] << " ";
    }
    cout << endl;

    return 0;
}