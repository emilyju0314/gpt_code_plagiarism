#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> visitors;
    for (int i = 0; i < n; i++) {
        int h, m;
        cin >> h >> m;
        visitors.push_back(make_pair(h, m));
    }

    sort(visitors.begin(), visitors.end());

    int max_cashes = 0;
    int current_cashes = 0;

    for (int i = 0; i < n; i++) {
        if (i == 0 || visitors[i] != visitors[i - 1]) {
            current_cashes = 1;
        } else {
            current_cashes++;
        }

        max_cashes = max(max_cashes, current_cashes);
    }

    cout << max_cashes << endl;

    return 0;
}