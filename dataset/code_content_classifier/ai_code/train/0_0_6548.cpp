#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> markedCells(n);
    for(int i = 0; i < n; i++) {
        cin >> markedCells[i];
    }

    set<pair<int, int>> markedPairs;
    for(int i = 0; i < n; i++) {
        markedPairs.insert({i, markedCells[i] - 1});
    }

    vector<int> rowPrefixSum(n, 0);
    vector<int> colPrefixSum(n, 0);
    for(auto p : markedPairs) {
        rowPrefixSum[p.first]++;
        colPrefixSum[p.second]++;
    }

    vector<int> rowBeautifulCount(n, 0);
    vector<int> colBeautifulCount(n, 0);
    for(auto p : markedPairs) {
        rowBeautifulCount[p.first] += colPrefixSum[p.second];
        colBeautifulCount[p.second] += rowPrefixSum[p.first];
    }

    for(int i = 1; i < n; i++) {
        rowPrefixSum[i] += rowPrefixSum[i - 1];
        colPrefixSum[i] += colPrefixSum[i - 1];
        rowBeautifulCount[i] += rowBeautifulCount[i - 1];
        colBeautifulCount[i] += colBeautifulCount[i - 1];
    }

    for(int i = 0; i < q; i++) {
        int l, d, r, u;
        cin >> l >> d >> r >> u;

        int beautyDegree = rowBeautifulCount[u - 1] - (d > 1 ? rowBeautifulCount[d - 2] : 0);
        beautyDegree += colBeautifulCount[r - 1] - (l > 1 ? colBeautifulCount[l - 2] : 0);
        cout << beautyDegree << endl;
    }

    return 0;
}