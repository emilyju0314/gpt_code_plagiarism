#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> b(n);
    unordered_map<long long, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        freq[b[i]]++;
    }

    sort(b.begin(), b.end());

    vector<long long> a(n);
    a[0] = b[0];

    for (int i = 1; i < n; i++) {
        a[i] = a[i-1] ^ b[i];
    }

    bool valid_permutation = true;
    for (int i = 1; i < n; i++) {
        if (a[i] <= a[i-1]) {
            valid_permutation = false;
            break;
        }
    }

    if (valid_permutation) {
        cout << "Yes" << endl;
        for (int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
    } else {
        cout << "No";
    }

    return 0;
}