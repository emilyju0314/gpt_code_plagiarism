#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> strengths(n);
    for(int i = 0; i < n; i++) {
        cin >> strengths[i];
    }

    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int l, r;
        cin >> l >> r;

        int eatCount = 0;
        for(int j = l-1; j < r; j++) {
            int battlePoints = 0;
            for(int k = l-1; k < r; k++) {
                if(j != k && (strengths[j] % strengths[k] == 0 || strengths[k] % strengths[j] == 0)) {
                    battlePoints++;
                }
            }
            if(battlePoints == r - l) {
                eatCount++;
            }
        }

        cout << (r - l + 1) - eatCount << endl;
    }

    return 0;
}