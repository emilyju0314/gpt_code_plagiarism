#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> bosses(n);

        for (int j = 0; j < n; j++) {
            cin >> bosses[j];
        }

        int totalSkips = 0;
        int skipsLeft = 0;

        for (int j = 0; j < n; j++) {
            if (bosses[j] == 1) {
                if (skipsLeft > 0) {
                    skipsLeft--;
                } else {
                    totalSkips++;
                    skipsLeft = 1;
                }
            }
        }

        cout << totalSkips << endl;
    }

    return 0;
}