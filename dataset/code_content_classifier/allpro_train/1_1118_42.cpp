#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(2));
    for (int i = 0; i < n; i++) cin >> v[i][0];
    for (int i = 0; i < n; i++) cin >> v[i][1];

    vector<int> l;
    vector<int> r;
    for (int i = 0; i < n; i++) (v[i][0] > 0 ? l : r).push_back(v[i][1]);

    if (l.size() == 0 || r.size() == 0)cout << 0 << endl;
    else {
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());
        cout << l[0] + r[0] << endl;
    }
    return 0;
}
