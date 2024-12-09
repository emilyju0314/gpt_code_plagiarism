#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> strengths(n);
        for (int i = 0; i < n; i++) {
            cin >> strengths[i];
        }

        int passes = 0;
        int currentPos = 0;
        
        while (true) {
            bool allOnes = true;
            for (int i = 0; i < n; i++) {
                if (strengths[i] != 1) {
                    allOnes = false;
                }
            }

            if (allOnes) {
                break;
            }

            if (currentPos + strengths[currentPos] < n) {
                strengths[currentPos + strengths[currentPos]] = max(strengths[currentPos + strengths[currentPos]] - 1, 1);
                currentPos += strengths[currentPos];
            } else {
                break;
            }

            passes++;
        }

        cout << passes << endl;
    }

    return 0;
}