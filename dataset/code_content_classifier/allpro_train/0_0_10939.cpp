#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k, t;
    cin >> n >> m >> k >> t;

    vector<pair<int, int>> flights(k);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        flights[i] = make_pair(x, y);
    }

    vector<int> companies(k, 1);
    int unevenness = 0;

    for (int i = 0; i < k; i++) {
        companies[i] = (i % t) + 1;
    }

    cout << t << endl;
    for (int i = 0; i < k; i++) {
        cout << companies[i] << " ";
    }

    return 0;
}