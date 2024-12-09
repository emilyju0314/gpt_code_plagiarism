#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        unordered_set<int> blockedCols;
        for(int j = 0; j < m; j++) {
            int row, col;
            cin >> row >> col;
            blockedCols.insert(col);
        }

        int cnt1 = 0, cnt2 = 0;

        for(int j = 1; j <= n; j++) {
            if(blockedCols.find(j) == blockedCols.end()) {
                if(j % 2 == 0) {
                    cnt2++;
                } else {
                    cnt1++;
                }
            }
        }

        if(cnt1 == cnt2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}