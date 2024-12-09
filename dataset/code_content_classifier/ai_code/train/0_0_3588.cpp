#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> segments(n);
    map<int, int> colors;
    
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        segments[i] = {l, r};
    }

    sort(segments.begin(), segments.end());

    for (int i = 0; i < n; i++) {
        colors[segments[i].first] = i % 2;
    }

    for (int i = 0; i < n; i++) {
        cout << colors[segments[i].first] << " ";
    }

    return 0;
}