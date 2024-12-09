#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> painters;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        painters.push_back({l, r});
    }

    int maxSections = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int sections = 0;
            for (int k = 0; k < q; k++) {
                if (painters[k].first <= i && painters[k].second >= j) {
                    sections += j - i + 1;
                    break;
                }
            }
            maxSections = max(maxSections, sections);
        }
    }

    cout << maxSections << endl;

    return 0;
}