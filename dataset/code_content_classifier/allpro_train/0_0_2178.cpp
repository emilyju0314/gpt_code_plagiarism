#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool checkPossibleSetOfTerritories(vector<pair<int, int>>& castles) {
    set<int> xCoords, yCoords;
    
    for (auto castle : castles) {
        xCoords.insert(castle.first);
        xCoords.insert(castle.second);
        yCoords.insert(castle.first);
        yCoords.insert(castle.second);
    }
    
    return xCoords.size() == 2 && yCoords.size() == 2;
}

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> castles;
    
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        castles.push_back({a, c});
        castles.push_back({b, d});
    }
    
    if (checkPossibleSetOfTerritories(castles)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}