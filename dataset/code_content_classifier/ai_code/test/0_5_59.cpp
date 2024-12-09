#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<vector<int>> schedule(n, vector<int>(5));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 5; k++) {
                cin >> schedule[j][k];
            }
        }

        bool possible = false;
        for (int j = 0; j < 5; j++) {
            for (int k = j+1; k < 5; k++) {
                int count_j = 0, count_k = 0;
                vector<int> students_j, students_k;

                for (int l = 0; l < n; l++) {
                    if (schedule[l][j] == 1 && schedule[l][k] == 0) {
                        count_j++;
                        students_j.push_back(l);
                    } else if (schedule[l][j] == 0 && schedule[l][k] == 1) {
                        count_k++;
                        students_k.push_back(l);
                    }
                }

                if (count_j == count_k && count_j + count_k == n) {
                    possible = true;
                    break;
                }
            }
            if (possible) {
                break;
            }
        }

        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}