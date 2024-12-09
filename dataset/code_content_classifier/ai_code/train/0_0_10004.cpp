#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> needsCosts(n);
    for(int i = 0; i < n; i++) {
        int a, p;
        cin >> a >> p;
        needsCosts[i] = make_pair(a, p);
    }

    int minCost = 0;
    int minPrice = needsCosts[0].second;
    minCost += needsCosts[0].first * minPrice;

    for(int i = 1; i < n; i++) {
        minPrice = min(minPrice, needsCosts[i].second);
        minCost += needsCosts[i].first * minPrice;
    }

    cout << minCost << endl;

    return 0;
}