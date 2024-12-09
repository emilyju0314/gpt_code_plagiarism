#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> prefSum(n+1, 0);
    for(int i = 0; i < n; i++) {
        prefSum[i+1] = prefSum[i];
        if(s[i] == '>' && (i == 0 || s[i-1] == '>')) {
            prefSum[i+1]++;
        }
    }

    int maxHoleCount = 0;
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        int newBallsCount = prefSum[r+1] - prefSum[l];
        int oldBallsCount = max(0, l > 0 ? prefSum[l] - prefSum[l-1] : 0);

        maxHoleCount = max(maxHoleCount, newBallsCount + oldBallsCount);

        cout << maxHoleCount << endl;
    }

    return 0;
}