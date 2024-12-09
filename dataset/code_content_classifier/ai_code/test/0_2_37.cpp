#include <iostream>
#include <vector>

using namespace std;

void constructTree(int n, int m, vector<vector<int>>& restrictions) {
    vector<int> parent(n+1);
    for(int i=1; i<=n; i++)
        parent[i] = i;

    for(int i=0; i<m; i++) {
        int a = restrictions[i][0];
        int b = restrictions[i][1];
        int c = restrictions[i][2];

        parent[b] = a;
    }

    int root = 1;
    while(parent[root] != root)
        root = parent[root];

    for(int i=1; i<=n; i++) {
        if(i != root)
            cout << i << " " << parent[i] << "\n";
    }
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> restrictions(m, vector<int>(3));
        for(int i=0; i<m; i++) {
            cin >> restrictions[i][0] >> restrictions[i][1] >> restrictions[i][2];
        }

        constructTree(n, m, restrictions);
    }

    return 0;
}