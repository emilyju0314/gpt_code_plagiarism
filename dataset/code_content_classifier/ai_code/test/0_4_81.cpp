#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> alpinists;
    for (int i = 0; i < n; i++) {
        int s, a;
        cin >> s >> a;
        alpinists.push_back(make_pair(s, a));
    }

    sort(alpinists.begin(), alpinists.end(), greater<pair<int, int>>());

    int maxAlpinists = 0;
    for (auto& alpinist : alpinists) {
        if (alpinist.first >= d) {
            d = max(d, alpinist.second);
            maxAlpinists++;
        }
    }

    cout << maxAlpinists << endl;

    return 0;
}