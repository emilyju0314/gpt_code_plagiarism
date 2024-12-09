#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<vector<int>> schedule(n, vector<int>(5));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 5; j++) {
                cin >> schedule[i][j];
            }
        }

        bool possible = false;
        for(int i = 0; i < 5; i++) {
            for(int j = i+1; j < 5; j++) {
                int group1 = 0, group2 = 0;
                for(int k = 0; k < n; k++) {
                    if(schedule[k][i] == 1 && schedule[k][j] == 0) {
                        group1++;
                    } else if(schedule[k][i] == 0 && schedule[k][j] == 1) {
                        group2++;
                    }
                }
                if(group1 + group2 == n && group1 == group2) {
                    possible = true;
                    break;
                }
            }
            if(possible) break;
        }

        if(possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}