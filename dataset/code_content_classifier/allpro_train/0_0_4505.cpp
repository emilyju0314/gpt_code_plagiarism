#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> powers(2*n);
    for (int i = 0; i < 2*n; i++) {
        cin >> powers[i];
    }
    
    vector<int> strong_pairs(2*n, -1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        strong_pairs[a-1] = b-1;
        strong_pairs[b-1] = a-1;
    }
    
    int team;
    cin >> team;
    
    if (team == 1) {
        for (int i = 0; i < n; i++) {
            int best_hero = -1;
            int best_power = 0;
            for (int j = 0; j < 2*n; j++) {
                if (powers[j] > best_power && (strong_pairs[j] == -1 || powers[strong_pairs[j]] == 0)) {
                    best_power = powers[j];
                    best_hero = j;
                }
            }
            cout << best_hero + 1 << endl;
            cout.flush();
            powers[best_hero] = 0;
            if (strong_pairs[best_hero] != -1) {
                powers[strong_pairs[best_hero]] = 0;
            }
            int opponent_hero;
            cin >> opponent_hero;
            powers[opponent_hero-1] = 0;
            if (strong_pairs[opponent_hero-1] != -1) {
                powers[strong_pairs[opponent_hero-1]] = 0;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            int opponent_hero;
            cin >> opponent_hero;
            powers[opponent_hero-1] = 0;
            if (strong_pairs[opponent_hero-1] != -1) {
                powers[strong_pairs[opponent_hero-1]] = 0;
            }
            int best_hero = -1;
            int best_power = 0;
            for (int j = 0; j < 2*n; j++) {
                if (powers[j] > best_power && (strong_pairs[j] == -1 || powers[strong_pairs[j]] == 0)) {
                    best_power = powers[j];
                    best_hero = j;
                }
            }
            cout << best_hero + 1 << endl;
            cout.flush();
            powers[best_hero] = 0;
            if (strong_pairs[best_hero] != -1) {
                powers[strong_pairs[best_hero]] = 0;
            }
        }
    }
    
    return 0;
}