#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string A, B;
        cin >> A >> B;

        vector<int> moves(20, 0);
        int min_moves = 0;

        for(int i = 0; i < n; i++) {
            if (A[i] > B[i]) {
                min_moves = -1;
                break;
            } else if (A[i] < B[i]) {
                int diff = B[i] - A[i];
                moves[diff]++;
            }
        }

        if (min_moves != -1) {
            for(int i = 1; i < 20; i++) {
                if (moves[i] != 0) {
                    min_moves++;
                }
            }
        }

        cout << min_moves << endl;
    }

    return 0;
}