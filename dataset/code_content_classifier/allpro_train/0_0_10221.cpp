#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    vector<int> P(1 << N);
    for(int i = 0; i < (1 << N); i++) {
        cin >> P[i];
    }

    vector<int> positions(1 << N);
    for(int i = 0; i < (1 << N); i++) {
        positions[P[i]-1] = i;
    }

    vector<int> winners(1 << N);
    for(int i = 0; i < (1 << N); i++) {
        int index = i;
        winners[i] = P[index];
    }

    for(int k = 0; k < (1 << N); k++) {
        vector<int> temp_positions = positions;
        for(int i = 0; i < (1 << N); i++) {
            temp_positions[i] = positions[(i+k) % (1 << N)];
        }

        vector<int> temp_winners = winners;
        for(int i = 0; i < (1 << N); i += 2) {
            int y = temp_positions[i];
            int x = temp_positions[i+1];
            int delta = (y - x + (1 << N)) % (1 << N);
            if(S[delta] == '0') {
                temp_winners[i/2] = temp_winners[i];
            } else {
                temp_winners[i/2] = temp_winners[i+1];
            }
        }

        winners = temp_winners;

        for(int i = 0; i < (1 << N); i++) {
            cout << winners[i] << endl;
        }
    }

    return 0;
}