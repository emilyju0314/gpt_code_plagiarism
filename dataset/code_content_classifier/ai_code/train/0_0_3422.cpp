#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    // Reading the advertisers for each slot
    vector<int> slots(n);
    for (int i = 0; i < n; i++) {
        cin >> slots[i];
    }

    // Process each query
    for (int i = 0; i < m; i++) {
        int query_type, l, r, id;
        cin >> query_type >> l >> r;

        if (query_type == 1) {
            cin >> id;
            for (int j = l-1; j < r; j++) {
                slots[j] = id;
            }
        } else {
            vector<int> freq(150001, 0); // Count frequencies of each advertiser
            for (int j = l-1; j < r; j++) {
                freq[slots[j]]++;
            }

            vector<int> advertisers;
            for (int j = 1; j < freq.size(); j++) {
                if (freq[j] >= (r - l + 1) * p / 100) {
                    advertisers.push_back(j);
                }
            }

            cout << advertisers.size() << " ";
            for (int j = 0; j < advertisers.size(); j++) {
                cout << advertisers[j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}