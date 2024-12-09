#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> imps(n);
    vector<int> prefixSum(n+1, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> imps[i];
        prefixSum[i+1] = prefixSum[i] + imps[i];
    }

    int q;
    cin >> q;

    while(q--) {
        int type, a, b, k;
        cin >> type >> a >> b;

        if (type == 1) {
            cin >> k;
            for (int i = a; i <= b; i++) {
                imps[i] += k;
                prefixSum[i+1] = prefixSum[i] + imps[i];
            }
        } else {
            int totalImps = prefixSum[b+1] - prefixSum[a];
            int l = a, r = b;

            if (imps[l] >= totalImps || imps[r] >= totalImps) {
                cout << "1" << endl;
            } else {
                cout << "0" << endl;
            }
        }
    }

    return 0;
}