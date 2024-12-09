#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> pink(n+1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        pink[u] = v;
    }

    int candidate = 1;
    for (int i = 1; i <= n; i++) {
        if (i == candidate) continue;

        cout << "? " << candidate << " " << i << endl;
        cout.flush();
        int ans;
        cin >> ans;

        if (ans == 1 && pink[candidate] == 0) {
            candidate = i;
        } else if (ans == 0 && pink[i] == 0) {
            candidate = i;
        }
    }

    cout << "! " << candidate << endl;

    return 0;
}