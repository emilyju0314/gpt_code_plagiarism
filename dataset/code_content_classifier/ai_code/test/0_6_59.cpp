#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<vector<int>> days(n, vector<int>(5));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 5; j++) {
                cin >> days[i][j];
            }
        }

        bool possible = false;

        for(int i = 0; i < 5; i++) {
            for(int j = i + 1; j < 5; j++) {
                int count_i = 0, count_j = 0;

                for(int k = 0; k < n; k++) {
                    if(days[k][i] == 1) count_i++;
                    if(days[k][j] == 1) count_j++;
                }

                if(count_i == n/2 && count_j == n/2) {
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