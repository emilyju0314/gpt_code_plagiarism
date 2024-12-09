#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        int xor_val = 0;
        for (int j = i; j < n; j++) {
            xor_val ^= arr[j];
            if (s.count(xor_val)) {
                cout << -1 << endl;
                return 0;
            }
            s.insert(xor_val);
        }
    }

    cout << n << endl;

    return 0;
}