#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, pair<int, int>>> colors;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        colors.push_back(make_pair(a ^ b, make_pair(2*i + 1, 2*i + 2)));
    }

    sort(colors.rbegin(), colors.rend());

    int max_beauty = colors[0].first;
    cout << max_beauty << endl;

    for (int i = 0; i < n; i++) {
        cout << colors[i].second.first << " " << colors[i].second.second << " ";
    }

    return 0;
}