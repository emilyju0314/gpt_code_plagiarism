#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }

        int max_num = *max_element(a.begin(), a.end());
        int mask = (1 << (in_bits+1)) - 1;
        vector<int> possible_k;

        for (int k = 1; k <= 30; k++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if ((a[j] & (mask ^ ((1 << k) - 1))) == 0) {
                    count++;
                }
            }
            if (count == n) {
                possible_k.push_back(k);
            }
        }

        for (int j = 0; j < possible_k.size(); j++) {
            cout << possible_k[j] << " ";
        }
        cout << endl;
    }

    return 0;
}