#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findPossibleAgariTiles(vector<int> handTiles) {
    vector<int> agariTiles;
    
    sort(handTiles.begin(), handTiles.end());
    
    for (int i = 1; i <= 12; i++) {
        if (count(handTiles.begin(), handTiles.end(), i) < 4) {
            vector<int> newHandTiles = handTiles;
            newHandTiles.push_back(i);
            sort(newHandTiles.begin(), newHandTiles.end());
            
            bool agari = true;
            for (int j = 0; j < newHandTiles.size(); j++) {
                if (j + 2 < newHandTiles.size()) {
                    if (newHandTiles[j] == newHandTiles[j + 1] && newHandTiles[j] == newHandTiles[j + 2]) {
                        j += 2;
                    } else if (newHandTiles[j] == newHandTiles[j + 1] - 1 && newHandTiles[j] == newHandTiles[j + 2] - 2) {
                        j += 2;
                    } else {
                        agari = false;
                        break;
                    }
                }
            }
            
            if (agari) {
                agariTiles.push_back(i);
            }
        }
    }
    
    return agariTiles;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> handTiles;
    for (int i = 0; i < 3*n + 1; i++) {
        string tile;
        cin >> tile;
        
        if (tile == "*") {
            handTiles.push_back(-1);
        } else {
            handTiles.push_back(stoi(tile));
        }
    }
    
    vector<int> agariTiles = findPossibleAgariTiles(handTiles);
    
    if (agariTiles.size() == 0) {
        cout << "-1" << endl;
    } else {
        for (int i = 0; i < agariTiles.size(); i++) {
            cout << agariTiles[i] << endl;
        }
    }
    
    return 0;
}