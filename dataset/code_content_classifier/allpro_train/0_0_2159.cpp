#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int Q, L;
    while (true) {
        cin >> Q >> L;
        if (Q == 0 && L == 0) {
            cout << "end" << endl;
            break;
        }
        
        int dist = 0;
        vector<int> invaders;
        
        for (int i = 0; i < Q; i++) {
            int query;
            cin >> query;
            
            if (query == 0) {
                int newPos;
                cin >> newPos;
                dist = newPos;
            
            } else if (query == 1) {
                int d;
                cin >> d;
                dist -= d;
                int damaged = 0;
                for (int j = 0; j < invaders.size(); j++) {
                    if (invaders[j] >= dist) {
                        damaged++;
                    }
                }
                invaders.erase(remove_if(invaders.begin(), invaders.end(), [dist] (int pos) { return pos >= dist; }), invaders.end());
                cout << "damage " << damaged << endl;
            
            } else if (query == 2) {
                int k;
                cin >> k;
                if (invaders.size() >= k) {
                    cout << "hit" << endl;
                    invaders.erase(invaders.begin() + k - 1);
                } else {
                    cout << "miss" << endl;
                }
            
            } else if (query == 3) {
                int x, r;
                cin >> x >> r;
                int killed = 0;
                for (int j = 0; j < invaders.size(); j++) {
                    if (abs(invaders[j] - dist) <= r && abs(invaders[j] - x) <= r) {
                        killed++;
                    }
                }
                invaders.erase(remove_if(invaders.begin(), invaders.end(), [dist, x, r] (int pos) { return abs(pos - dist) <= r && abs(pos - x) <= r; }), invaders.end());
                cout << "bomb " << killed << endl;
            
            } else if (query == 4) {
                int k;
                cin >> k;
                if (invaders.size() >= k) {
                    cout << "distance " << abs(invaders[k - 1] - dist) << endl;
                } else {
                    cout << "distance -1" << endl;
                }
            }
        }
    }

    return 0;
}