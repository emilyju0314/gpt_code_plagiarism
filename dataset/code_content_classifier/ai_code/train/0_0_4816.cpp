#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> image(n);
    for (int i = 0; i < n; i++) {
        cin >> image[i];
    }

    int min_toggles = n * m;
    for (int k = 2; k <= min(n, m); k++) {
        int padded_n = (n + k - 1) / k * k;
        int padded_m = (m + k - 1) / k * k;

        int toggles = 0;
        for (int i = 0; i < padded_n; i++) {
            for (int j = 0; j < padded_m; j++) {
                int val = 0;
                for (int ii = 0; ii < k; ii++) {
                    for (int jj = 0; jj < k; jj++) {
                        int ni = i + ii;
                        int nj = j + jj;
                        if (ni < n && nj < m) {
                            if (image[ni][nj] == '1') {
                                val = 1;
                            }
                        }
                    }
                }
                if (val == 0) {
                    toggles++;
                }
            }
        }
        min_toggles = min(min_toggles, toggles);
    }

    cout << min_toggles << endl;

    return 0;
}