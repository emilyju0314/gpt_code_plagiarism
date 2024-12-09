#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> W(n, vector<int>(n));
    vector<vector<int>> E(n, vector<int>(n));
    vector<string> F(n);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> W[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> E[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        cin >> F[i];
    }

    int mincost = 0;
    vector<pair<int, int>> operations;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(F[i][j] == '.') {
                mincost += min(W[i][j], E[i][j]);
                if(W[i][j] < E[i][j]) {
                    operations.push_back({i+1, j+1});
                }
            }
        }
    }

    cout << mincost << endl;
    cout << operations.size() << endl;
    
    for(auto op : operations) {
        cout << op.first << " " << op.second << " ";
        if(W[op.first-1][op.second-1] < E[op.first-1][op.second-1]) {
            cout << "write" << endl;
        } else {
            cout << "erase" << endl;
        }
    }

    return 0;
}