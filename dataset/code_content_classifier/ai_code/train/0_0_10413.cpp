#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main() {
    int N, S, D;
    cin >> N >> S >> D;

    vector<bitset<1001>> switches;
    for(int i=0; i<S; i++) {
        int C;
        cin >> C;
        bitset<1001> switch_mask;
        for(int j=0; j<C; j++) {
            int bulb_index;
            cin >> bulb_index;
            switch_mask.set(bulb_index);
        }
        switches.push_back(switch_mask);
    }

    for(int i=0; i<D; i++) {
        int T;
        cin >> T;
        bitset<1001> bulbs_on;
        for(int j=0; j<T; j++) {
            int bulb_index;
            cin >> bulb_index;
            bulbs_on.set(bulb_index);
        }

        int min_switches = S+1;
        for(int j=0; j<(1<<S); j++) {
            bitset<1001> bulbs_off;
            int num_switches = 0;
            for(int k=0; k<S; k++) {
                if(j & (1<<k)) {
                    bulbs_off ^= switches[k];
                    num_switches++;
                }
            }
            if((bulbs_on ^ bulbs_off).count() == 0) {
                min_switches = min(min_switches, num_switches);
            }
        }
        if(min_switches == S+1) {
            cout << -1 << endl;
        } else {
            cout << min_switches << endl;
        }
    }

    return 0;
}