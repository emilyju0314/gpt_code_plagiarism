#include <iostream>
#include <vector>

using namespace std;

bool canWin(int N, vector<vector<int>>& amidakuji) {
    vector<int> order(N-1, 0); // Store the order of parts
    vector<bool> visited(N-1, false);
    bool flag = false;
    
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < N-1; j++) {
            if (!visited[j] && amidakuji[j][0] == 0) {
                order[i] = j + 1;
                visited[j] = true;
                
                bool valid = true;
                for (int k = 1; k < N-1; k++) {
                    if (amidakuji[j][k] == 1) {
                        if (!visited[k]) {
                            valid = false;
                        } else {
                            i++;
                            order[i] = k + 1;
                        }
                    }
                }
                
                if (!valid) {
                    flag = true;
                    break;
                }
            }
        }
        
        if (flag) {
            break;
        }
    }
    
    if (flag) {
        return false;
    } else {
        cout << "yes" << endl;
        for (int i = 0; i < N-1; i++) {
            cout << order[i] << endl;
        }
        return true;
    }
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> amidakuji(N-1, vector<int>(N-1));
    
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < N-1; j++) {
            cin >> amidakuji[i][j];
        }
    }
    
    if (!canWin(N, amidakuji)) {
        cout << "no" << endl;
    }
    
    return 0;
}