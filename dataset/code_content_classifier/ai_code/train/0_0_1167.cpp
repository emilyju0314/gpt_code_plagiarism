#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> taste(n);
    vector<int> calories(n);

    for (int i = 0; i < n; i++) {
        cin >> taste[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> calories[i];
    }

    int maxTaste = -1;

    for (int bitmask = 0; bitmask < (1 << n); bitmask++) {
        int totalTaste = 0;
        int totalCalories = 0;

        for (int i = 0; i < n; i++) {
            if (bitmask & (1 << i)) {
                totalTaste += taste[i];
                totalCalories += calories[i];
            }
        }

        if (totalCalories > 0 && totalTaste * k == totalCalories) {
            maxTaste = max(maxTaste, totalTaste);
        }
    }

    cout << maxTaste << endl;

    return 0;
}