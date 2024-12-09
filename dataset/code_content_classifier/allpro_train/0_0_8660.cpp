#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    if (x == 0) {
        for (int i = 0; i < n; i++) {
            if (freq[arr[i]] > 1) {
                cout << 0 << endl;
                return 0;
            }
        }
        cout << -1 << endl;
    } else {
        for (int i = 0; i < n; i++) {
            if (freq[arr[i] & x] > 0 && (arr[i] & x) != arr[i]) {
                cout << 1 << endl;
                return 0;
            }
        }
        for (int i = 0; i < n; i++) {
            if (freq[arr[i] & x] > 1) {
                cout << 1 << endl;
                return 0;
            }
        }
        cout << 2 << endl;
    }

    return 0;
}