#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, p, q, r;
    cin >> n >> p >> q >> r;

    vector<int> strength(n), defense(n), speed(n);
    for(int i = 0; i < n; i++) {
        cin >> strength[i] >> defense[i] >> speed[i];
    }

    int max_strength = *max_element(strength.begin(), strength.end());
    int max_defense = *max_element(defense.begin(), defense.end());
    int max_speed = *max_element(speed.begin(), speed.end());

    int count = 0;
    for(int i = 1; i <= p; i++) {
        for(int j = 1; j <= q; j++) {
            for(int k = 1; k <= r; k++) {
                bool can_beat = false;
                for(int l = 0; l < n; l++) {
                    if((i > strength[l] && j > defense[l]) || (i > strength[l] && k > speed[l]) || (j > defense[l] && k > speed[l])) {
                        can_beat = true;
                        break;
                    }
                }
                if(can_beat) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}