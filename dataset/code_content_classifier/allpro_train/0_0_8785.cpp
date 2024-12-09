#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int m, k;
        cin >> m >> k;

        vector<int> portions(k);
        for (int j = 0; j < k; j++) {
            cin >> portions[j];
        }

        vector<vector<int>> observations(m-1, vector<int>(2));
        for (int j = 0; j < m-1; j++) {
            cin >> observations[j][0] >> observations[j][1];
        }

        vector<int> dishesLeft(portions);

        for (int j = 0; j < m-1; j++) {
            if (observations[j][0] != 0 && observations[j][1] == 1) {
                dishesLeft[observations[j][0]-1]--;
            }
        }

        vector<char> result(k, 'N');
        for (int j = 0; j < k; j++) {
            for (int l = 0; l < m-1; l++) {
                if (observations[l][0] == 0 || (observations[l][0] == j+1 && observations[l][1] == 0)) {
                    result[j] = 'Y';
                    break;
                }
            }
        }

        for (char c : result) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}