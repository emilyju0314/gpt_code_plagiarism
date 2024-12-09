#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> piles(n);
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    set<int> s(piles.begin(), piles.end());
    vector<int> uniquePiles(s.begin(), s.end());

    int totalMoves = 0;
    for (int i = 1; i < uniquePiles.size(); i++) {
        totalMoves += abs(uniquePiles[i] - uniquePiles[i-1]);
    }

    cout << totalMoves << endl;

    while (q--) {
        int t, x;
        cin >> t >> x;

        if (t == 0) {
            auto it = lower_bound(uniquePiles.begin(), uniquePiles.end(), x);
            totalMoves -= it == uniquePiles.begin() ? 0 : *it - *(--it);
            totalMoves -= it == uniquePiles.end() ? 0 : *it - x;
            uniquePiles.erase(x);
        } else {
            uniquePiles.insert(x);
            auto it = uniquePiles.find(x);
            totalMoves += (it == uniquePiles.begin() || it == prev(uniquePiles.end())) ? 0 : *prev(it) - x + x - *next(it);
        }

        cout << totalMoves << endl;
    }

    return 0;
}