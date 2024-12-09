#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // Variables to store the total fish and meat for each dish
        vector<int> totalFish(n, 0);
        vector<int> totalMeat(n, 0);

        // Variables to store the minimum variety and the corresponding fish and meat amounts
        int minVariety = 0;
        vector<pair<int, int>> fishMeatAmounts(n);

        for (int i = 0; i < n; i++) {
            int a, b, m;
            cin >> a >> b >> m;

            totalFish[i] = a;
            totalMeat[i] = b;

            fishMeatAmounts[i] = make_pair(0, m); // Initialize with 0 fish and m meat

            minVariety++;
        }

        cout << minVariety << endl;

        // Output the fish and meat amounts for each dish to achieve the minimum variety
        for (int i = 0; i < n; i++) {
            cout << fishMeatAmounts[i].first << " " << fishMeatAmounts[i].second << endl;
        }
    }

    return 0;
}