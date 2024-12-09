#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> spotlights;
    for (int i = 0; i < n; i++) {
        int a, l;
        cin >> a >> l;
        spotlights.push_back({ a, l });
    }

    sort(spotlights.begin(), spotlights.end());

    int maxTotalLength = 0;
    int totalLength = 0;
    for (int i = 0; i < n; i++) {
        int a = spotlights[i].first;
        int l = spotlights[i].second;
        
        totalLength = max(totalLength + l, a + l);
        maxTotalLength = max(maxTotalLength, totalLength);
    }

    cout << maxTotalLength << endl;

    return 0;
}