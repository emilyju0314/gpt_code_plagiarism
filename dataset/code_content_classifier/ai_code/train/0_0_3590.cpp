#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> piles(n);
    vector<int> prefixSum(n);

    for (int i = 0; i < n; i++) {
        cin >> piles[i];
        prefixSum[i] = (i == 0) ? piles[i] : prefixSum[i - 1] + piles[i];
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int wormLabel;
        cin >> wormLabel;

        int pileNumber = lower_bound(prefixSum.begin(), prefixSum.end(), wormLabel) - prefixSum.begin() + 1;
        cout << pileNumber << endl;
    }

    return 0;
}