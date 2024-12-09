#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    while (cin >> n && n != 0) {
        vector<int> buns(n);
        int totalWeight = 0;

        for (int i = 0; i < n; i++) {
            cin >> buns[i];
            totalWeight += buns[i];
        }

        int bags[11] = {0}; // Initialize bags array with 0

        for (int i = 0; i < n; i++) {
            bags[buns[i]]++;
        }

        int maxSeparateBuns = 0;

        if (totalWeight >= 10) {
            for (int i = 1; i <= 9; i++) {
                if (i == 10 - i) {
                    maxSeparateBuns += bags[i] / 2;
                    bags[i] %= 2;
                } else {
                    int minCount = min(bags[i], bags[10 - i]);
                    maxSeparateBuns += minCount;
                    bags[i] -= minCount;
                    bags[10 - i] -= minCount;
                }
            }
            maxSeparateBuns += bags[10] / 2;
        }

        cout << maxSeparateBuns << endl;
    }

    return 0;
}