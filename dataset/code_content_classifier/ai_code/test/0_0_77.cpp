#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int getRoomSize(vector<vector<int>>& construction, int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return 0;
    }
    
    if (construction[i][j] == -1) {
        return 0;
    }
    
    int roomSize = 1;
    construction[i][j] = -1;
    
    roomSize += getRoomSize(construction, i-1, j);
    roomSize += getRoomSize(construction, i+1, j);
    roomSize += getRoomSize(construction, i, j-1);
    roomSize += getRoomSize(construction, i, j+1);
    
    return roomSize;
}

int main() {
    cin >> n >> m;
    
    vector<vector<int>> construction(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> construction[i][j];
        }
    }
    
    vector<int> roomSizes;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (construction[i][j] != -1) {
                roomSizes.push_back(getRoomSize(construction, i, j));
            }
        }
    }
    
    sort(roomSizes.rbegin(), roomSizes.rend());
    
    for (int size : roomSizes) {
        cout << size << " ";
    }
    
    return 0;
}