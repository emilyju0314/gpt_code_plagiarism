#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minShoesChange(vector<vector<int>>& dressingRoom, int n, int m) {
    int minChanges = 0;
    vector<pair<int, int>> coordinates[81];
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            coordinates[dressingRoom[i][j]].push_back({i, j});
        }
    }
    
    for(int i=1; i<=80; i++) {
        if(coordinates[i].size() == 2) {
            minChanges += abs(coordinates[i][0].first - coordinates[i][1].first) + abs(coordinates[i][0].second - coordinates[i][1].second);
        }
    }
    
    return minChanges;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> dressingRoom(n, vector<int>(m));
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> dressingRoom[i][j];
        }
    }
    
    cout << minShoesChange(dressingRoom, n, m) << endl;
    
    return 0;
}