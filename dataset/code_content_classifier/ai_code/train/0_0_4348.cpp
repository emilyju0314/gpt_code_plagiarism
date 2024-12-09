#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> know(n);
    for(int i = 0; i < n; i++) {
        cin >> know[i];
    }

    vector<int> answer(1 << (n-1), 0);

    for(int bitwise = 0; bitwise < (1 << (n-1)); bitwise++) {
        vector<int> permutation(n);
        permutation[0] = n;
        int cnt = 0;

        for(int i = 1; i < n; i++) {
            permutation[i] = 1 + permutation[i-1];
            for(int j = 0; j < n-1; j++) {
                if((bitwise & (1 << j)) && know[permutation[i-1] - 1][j] == '1') {
                    permutation[i]--;
                } else if(!(bitwise & (1 << j)) && know[permutation[i-1] - 1][j] == '0') {
                    permutation[i]--;
                }
            }
        }

        int inversions = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(permutation[i] > permutation[j]) {
                    inversions++;
                }
            }
        }

        if(inversions % 2 == 0) {
            answer[bitwise] = 1;
        }
    }

    for(int i = 0; i < (1 << (n-1)); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}