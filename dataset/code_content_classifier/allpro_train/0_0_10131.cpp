#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> values(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        values[i] = make_pair(a, b);
    }

    long long result = 0;
    for (int i = 0; i < m; i++) {
        int a, b, k;
        cin >> a >> b >> k;
        result += (values[a - 1].first * values[b - 1].second) * k;
    }

    cout << result << endl;

    return 0;
}