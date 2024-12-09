#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> freq;
    for (int num : a) {
        while (num > 0) {
            freq[num]++;
            num /= 2;
        }
    }

    int min_ops = INT_MAX;
    for (auto it = freq.begin(); it != freq.end(); it++) {
        if (it->second >= k) {
            min_ops = min(min_ops, it->second - k);
        }
    }

    cout << min_ops << endl;

    return 0;
}