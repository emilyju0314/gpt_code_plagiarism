#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, l;
    cin >> n >> k >> l;

    vector<int> staves(n*k);
    for(int i = 0; i < n*k; i++) {
        cin >> staves[i];
    }
    
    sort(staves.begin(), staves.end());

    int pivot = n*k - n;
    int barrel_idx = 0;
    while (barrel_idx < n && pivot < n*k) {
        if (staves[pivot] - staves[0] > l) {
            break;
        }
        pivot++;
        barrel_idx++;
    }

    if (barrel_idx < n) {
        cout << 0 << endl;
    } else {
        long long sum = 0;
        int stave_idx = 0;
        for (int i = 0; i < n; i++) {
            sum += staves[stave_idx];
            stave_idx += k;
        }
        cout << sum << endl;
    }

    return 0;
}