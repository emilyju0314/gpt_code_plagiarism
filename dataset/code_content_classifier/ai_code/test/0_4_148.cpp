#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int w, h;
        cin >> w >> h;

        vector<int> horizontal[2], vertical[2];

        for (int i = 0; i < 2; i++) {
            int k;
            cin >> k;

            horizontal[i].resize(k);
            for (int j = 0; j < k; j++) {
                cin >> horizontal[i][j];
            }
        }

        for (int i = 0; i < 2; i++) {
            int k;
            cin >> k;

            vertical[i].resize(k);
            for (int j = 0; j < k; j++) {
                cin >> vertical[i][j];
            }
        }

        int max_area = 0;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    max_area = max(max_area, max(horizontal[j][0], w - horizontal[j].back()) * max(vertical[k][0], h - vertical[k].back()));
                }
            }
        }

        cout << max_area * 2 << endl;
    }

    return 0;
}