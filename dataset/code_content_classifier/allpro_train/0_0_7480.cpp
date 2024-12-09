#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n;

    vector<pair<int, long long>> hills(n);
    for (int i = 0; i < n; i++) {
        int x;
        long long y;
        cin >> x >> y;
        hills[i] = {x, y};
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        int meeting_hill = max(hills[a-1].first, hills[b-1].first);

        cout << meeting_hill << " ";
    }

    return 0;
}