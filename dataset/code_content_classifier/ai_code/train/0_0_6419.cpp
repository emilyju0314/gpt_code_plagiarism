#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int k;
    cin >> k;

    while (k--) {
        int n;
        cin >> n;

        vector<int> planks(n);
        for (int i = 0; i < n; i++) {
            cin >> planks[i];
        }

        sort(planks.begin(), planks.end(), greater<int>());

        int sideLength = 0;
        for (int i = 0; i < n; i++) {
            int length = min(i+1, planks[i]);
            sideLength = max(sideLength, length);
        }

        cout << sideLength << endl;
    }

    return 0;
}