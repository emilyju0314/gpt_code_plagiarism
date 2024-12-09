#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int m, d;
    cin >> m >> d;
    
    vector<vector<vector<int>> > subspaces(m);
    unordered_map<vector<int>, int> groupMap;
    int groupNumber = 1;
    
    for(int i=0; i<m; i++) {
        int ki;
        cin >> ki;
        
        vector<vector<int>> vectors(ki, vector<int>(d));
        for(int j=0; j<ki; j++) {
            for(int k=0; k<d; k++) {
                cin >> vectors[j][k];
            }
        }
        
        int group = 0;
        for(const auto& entry : groupMap) {
            if(entry.first == vectors[0]) {
                group = entry.second;
                break;
            }
        }
        
        if(group == 0) {
            group = groupNumber;
            groupMap[vectors[0]] = groupNumber;
            groupNumber++;
        }
        
        subspaces[i] = vectors;
        
        for(int j=0; j<ki; j++) {
            groupMap[vectors[j]] = group;
        }
    }
    
    for(int i=0; i<m; i++) {
        cout << groupMap[subspaces[i][0]] << " ";
    }
    
    return 0;
}