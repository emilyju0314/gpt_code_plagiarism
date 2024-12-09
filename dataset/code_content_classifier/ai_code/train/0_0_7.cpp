#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> degrees(n+1, 0);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        degrees[u]++;
        degrees[v]++;
    }

    int leafCount = 0;
    for (int i = 1; i <= n; i++) {
        if (degrees[i] == 1) {
            leafCount++;
        }
    }

    if (leafCount == 1 || leafCount == 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}