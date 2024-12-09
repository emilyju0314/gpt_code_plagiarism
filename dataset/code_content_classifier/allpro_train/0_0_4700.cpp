#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    if (a == 0 && b == 0) {
        for (int i = 0; i < n; i++) {
            cout << "1 ";
        }
    } else {
        vector<int> groom_fortunes;

        int total_richness = 0;
        while (a > 0) {
            groom_fortunes.push_back(total_richness + 1);
            total_richness += total_richness + 1;
            a--;
        }

        while (b > 0) {
            groom_fortunes.push_back(total_richness + 1);
            b--;
        }

        while (a + b < n) {
            groom_fortunes.push_back(1);
        }

        if (groom_fortunes[groom_fortunes.size() - 1] <= total_richness) {
            cout << "-1";
        } else {
            for (int fortune : groom_fortunes) {
                cout << fortune << " ";
            }
        }
    }

    return 0;
}