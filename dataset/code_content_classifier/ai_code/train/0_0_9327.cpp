#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, w, m;
    cin >> n >> w >> m;

    double totalMilk = n * w;

    if (totalMilk < m * w || totalMilk > m * 2 * w) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;

        int bottlesNeeded = m;
        for (int i = 0; i < m; i++) {
            int bottlesToUse = 0;
            if (totalMilk >= w) {
                bottlesToUse = min(bottlesNeeded, 2);
            } else {
                bottlesToUse = 1;
            }

            for (int j = 1; j <= bottlesToUse; j++) {
                double milkToPour = min(totalMilk / bottlesToUse, w);
                cout << j << " " << fixed << setprecision(6) << milkToPour << " ";
                totalMilk -= milkToPour;
            }

            cout << endl;
            bottlesNeeded -= bottlesToUse;
        }
    }

    return 0;
}