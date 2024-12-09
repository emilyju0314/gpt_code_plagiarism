#include <iostream>
#include <vector>

using namespace std;

bool isValidTree(vector<vector<int>>& dist, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dist[i][j] != dist[j][i]) {
                return false;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(dist[i][i] != 0) {
            return false;
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    return false;
                }
            }
        }
    }
    
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> dist(n, vector<int>(n));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
    
    if(isValidTree(dist, n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}