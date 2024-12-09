#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValidMove(vector<string>& battlefield, int n, int m, int k, int player, int depth) {
    if (depth == 0) {
        return false;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (battlefield[i][j] == (player == 1 ? 'G' : 'R')) {
                // Try attack
                for (int x = j+1; x < m; x++) {
                    if (battlefield[i][x] == (player == 1 ? 'R' : 'G')) {
                        bool canAttack = true;
                        for (int y = j+1; y < x; y++) {
                            if (battlefield[i][y] != '-') {
                                canAttack = false;
                                break;
                            }
                        }
                        if (canAttack) {
                            for (int y = j+1; y < x; y++) {
                                battlefield[i][y] = (player == 1 ? 'G' : 'R');
                            }
                            return !isValidMove(battlefield, n, m, k, player == 1 ? 2 : 1, depth-1);
                        }
                    }
                }
                
                // Try retreat
                for (int x = j-1; x >= 0; x--) {
                    if (battlefield[i][x] == (player == 1 ? 'R' : 'G')) {
                        bool canRetreat = true;
                        for (int y = j-1; y > x; y--) {
                            if (battlefield[i][y] != '-') {
                                canRetreat = false;
                                break;
                            }
                        }
                        if (canRetreat) {
                            for (int y = j-1; y > x; y--) {
                                battlefield[i][y] = (player == 1 ? 'G' : 'R');
                            }
                            return !isValidMove(battlefield, n, m, k, player == 1 ? 2 : 1, depth-1);
                        }
                    }
                }
            }
        }
    }
    
    return true;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<string> battlefield(n);
    for (int i = 0; i < n; i++) {
        cin >> battlefield[i];
    }
    
    bool shrekWins = !isValidMove(battlefield, n, m, k, 1, k);
    
    if (shrekWins) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
    
    return 0;
}