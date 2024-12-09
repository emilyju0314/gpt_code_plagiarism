#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int h, n;
        cin >> h >> n;

        vector<int> platforms(n);
        for (int j = 0; j < n; j++) {
            cin >> platforms[j];
        }

        sort(platforms.begin(), platforms.end());

        int magic_crystals = 0;
        for (int j = 0; j < n; j++) {
            if (platforms[j] - 1 > 1) {
                if (j == 0 || (platforms[j - 1] - platforms[j] != 1)) {
                    magic_crystals++;
                }
            }
        }

        cout << magic_crystals << endl;
    }

    return 0;
}