#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int countRepaintedFaces(vector<vector<string>>& cubes) {
    unordered_map<string, int> faceCount;
    for(auto& cube : cubes) {
        for(auto& face : cube) {
            faceCount[face]++;
        }
    }
    
    int maxCount = 0;
    for(auto& entry : faceCount) {
        maxCount = max(maxCount, entry.second);
    }
    
    return cubes.size() * 6 - maxCount;
}

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        
        vector<vector<string>> cubes(n, vector<string>(6));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 6; j++) {
                cin >> cubes[i][j];
            }
        }
        
        int minRepainted = countRepaintedFaces(cubes);
        cout << minRepainted << endl;
    }
    
    return 0;
}