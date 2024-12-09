#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cells(3, vector<int>());
    map<pair<int, int>, int> cellColorMap;

    for(int i = 0; i < n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        cells[c-1].push_back(i);
        cellColorMap[{x,y}] = c;
    }

    int k = n;
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i==j) continue;
            
            vector<int> toRemove;
            for(int idx : cells[j]) {
                int x, y;
                for(pair<int, int> p : cellColorMap) {
                    if(p.second == i+1 && idx == p.second-1) {
                        x = p.first.first;
                        y = p.first.second;
                        break;
                    }
                }

                if(cellColorMap.count({x, y+1}) && cellColorMap.count({x+1, y}) && cellColorMap.count({x+1, y+1})) {
                    toRemove.push_back(i+1);
                    break;
                }
            }

            k = min(k, n - toRemove.size());
        }
    }

    cout << k << endl;

    return 0;
}