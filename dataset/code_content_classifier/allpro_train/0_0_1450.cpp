#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> seq(n);
    for(int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    sort(seq.begin(), seq.end());

    vector<long long> res(n);
    int idx = 0;
    for(int i = n-1; i >= 0; i--) {
        res[idx] = seq[i];
        idx += 2;
        if(idx >= n) {
            idx = 1;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }

    return 0;
}