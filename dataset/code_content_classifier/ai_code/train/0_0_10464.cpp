#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> getNextState(vector<vector<int>> state, int x, int y) {
    state[x][y] = 0;
    if(x-1 >= 0) state[x-1][y] = state[x-1][y] == 1 ? 0 : 1;
    if(x+1 < 8) state[x+1][y] = state[x+1][y] == 1 ? 0 : 1;
    if(y-1 >= 0) state[x][y-1] = state[x][y-1] == 1 ? 0 : 1;
    if(y+1 < 8) state[x][y+1] = state[x][y+1] == 1 ? 0 : 1;
    
    return state;
}

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cout << "Data " << i+1 << ":\n";
        string blankLine;
        getline(cin, blankLine); // read blank line
        
        vector<vector<int>> state(8, vector<int>(8));
        for(int j = 0; j < 8; j++) {
            string row;
            cin >> row;
            for(int k = 0; k < 8; k++) {
                state[j][k] = row[k] - '0';
            }
        }
        
        int x, y;
        cin >> x >> y;
        state = getNextState(state, x-1, y-1);
        
        for(int j = 0; j < 8; j++) {
            for(int k = 0; k < 8; k++) {
                cout << state[j][k];
            }
            cout << endl;
        }
    }
    
    return 0;
}