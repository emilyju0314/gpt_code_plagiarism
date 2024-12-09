#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k, z;
        cin >> n >> k >> z;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int maxScore = 0;
        
        for (int i = 0; i <= z; i++) {
            int score = 0;
            int moves = k - 2*i; // number of moves to the right
            for (int j = 0; j <= moves; j++) {
                score += a[j];
                if (j < n - 1) {
                    int total_moves = i + (moves - j)/2;
                    score += a[j+1]*min(total_moves, z-i);
                }
            }
            maxScore = max(maxScore, score);
        }
        
        cout << maxScore << endl;
    }

    return 0;
}