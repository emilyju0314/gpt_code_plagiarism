#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, S, D;
    cin >> N >> S >> D;
    
    vector<vector<int>> switches(S, vector<int>());
    for (int i = 0; i < S; i++) {
        int C;
        cin >> C;
        for (int j = 0; j < C; j++) {
            int bulb;
            cin >> bulb;
            switches[i].push_back(bulb);
        }
    }
    
    vector<int> bulbsOn(N + 1, 0);
    
    for (int i = 0; i < D; i++) {
        int T;
        cin >> T;
        fill(bulbsOn.begin(), bulbsOn.end(), 0);
        
        for (int j = 0; j < T; j++) {
            int bulb;
            cin >> bulb;
            bulbsOn[bulb] = 1;
        }

        int minSwitches = S + 1;
        for (int j = 0; j < (1 << S); j++) {
            vector<int> state(N + 1, 0);
            for (int k = 0; k < S; k++) {
                if (j & (1 << k)) {
                    for (int l : switches[k]) {
                        state[l] = 1 - state[l];
                    }
                }
            }
            
            bool valid = true;
            for (int l = 1; l <= N; l++) {
                if (state[l] != bulbsOn[l]) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                minSwitches = min(minSwitches, __builtin_popcount(j));
            }
        }
        
        if (minSwitches == S + 1) {
            cout << -1 << endl;
        } else {
            cout << minSwitches << endl;
        }
    }

    return 0;
}