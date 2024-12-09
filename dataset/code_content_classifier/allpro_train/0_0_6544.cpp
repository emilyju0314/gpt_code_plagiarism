#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int diff = (a[1] - a[0] + m) % m;
    unordered_map<int, bool> visited;
    for(int i = 1; i < n; i++) {
        int cur_diff = (a[i] - a[0] + m) % m;
        if(cur_diff != diff) {
            cout << -1 << endl;
            return 0;
        }

        visited[a[i]] = true;
    }

    for(int i = 1; i < n; i++) {
        int expected_val = (a[0] + i * diff) % m;
        if(!visited[expected_val]) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << a[0] << " " << diff << endl;

    return 0;
}