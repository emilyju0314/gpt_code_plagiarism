#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int q, x;
    cin >> q >> x;

    vector<int> freq(x);
    set<pair<int, int>> table;

    int mex = 0;

    for (int i = 0; i < q; i++) {
        int y;
        cin >> y;

        y %= x;
        freq[y]++;

        while (freq[mex % x] > 0) {
            freq[mex % x]--;
            table.insert({mex % x, mex});
            mex++;
        }

        cout << mex << endl;
    }

    return 0;
}