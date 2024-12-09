#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> lostArray(n);

    auto query = [&](int l, int r) {
        cout << "? " << l+1 << " " << r+1 << endl;
        cout.flush();
        int x, f;
        cin >> x >> f;
        return make_pair(x, f);
    };

    auto findMode = [&](int l, int r) {
        map<int, int> freq;
        for (int i = l; i <= r; i++) {
            auto res = query(i, i);
            freq[res.first]++;
        }

        int mode = -1, maxFreq = -1;
        for (auto it : freq) {
            if (it.second > maxFreq) {
                mode = it.first;
                maxFreq = it.second;
            }
        }

        return make_pair(mode, maxFreq);
    };

    int idx = 0;
    while (idx < n) {
        int r = min(idx+100, n-1);
        auto res = findMode(idx, r);
        int mode = res.first, freq = res.second;
        for (int i = 0; i < freq; i++) {
            lostArray[idx + i] = mode;
        }
        idx += freq;
    }

    cout << "! ";
    for (int i = 0; i < n; i++) {
        cout << lostArray[i] << " ";
    }
    cout << endl;
    cout.flush();

    return 0;
}