#include <iostream>
#include <vector>

using namespace std;

struct Ant {
    char direction;
    int position;
};

int main() {
    int n, l;
    
    while (true) {
        cin >> n >> l;
        if (n == 0 && l == 0) {
            break;
        }
        
        vector<Ant> ants(n);
        for (int i = 0; i < n; i++) {
            cin >> ants[i].direction >> ants[i].position;
        }
        
        bool has_met = true;
        int seconds = 0;
        int last_ant = -1;
        
        while (has_met) {
            has_met = false;
            int min_distance = l;
            
            for (int i = 0; i < n; i++) {
                int next_position;
                if (ants[i].direction == 'R') {
                    next_position = ants[i].position + 1;
                } else {
                    next_position = ants[i].position - 1;
                }
                
                for (int j = 0; j < n; j++) {
                    if (i != j && next_position == ants[j].position) {
                        has_met = true;
                        if (ants[i].position < min_distance) {
                            min_distance = ants[i].position;
                            last_ant = i + 1;
                        }
                    }
                }
            }
            
            if (!has_met) {
                for (int i = 0; i < n; i++) {
                    if (ants[i].direction == 'R') {
                        ants[i].position++;
                    } else {
                        ants[i].position--;
                    }
                }
            } else {
                for (int i = 0; i < n; i++) {
                    if (ants[i].direction == 'R') {
                        ants[i].direction = 'L';
                    } else {
                        ants[i].direction = 'R';
                    }
                }
            }
            
            seconds++;
        }
        
        cout << seconds << " " << last_ant << endl;
    }
    
    return 0;
}