#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> result(m+1, -1);
    result[0] = 0;

    for (int i = 0; i < n; i++) {
        int t, xi, yi;
        cin >> t >> xi >> yi;
        double x = xi / 100000.0;

        vector<int> new_result(m+1, -1);

        if (t == 1) {
            for (int j = 0; j <= m; j++) {
                if (result[j] != -1) {
                    for (int a = 0; a <= yi; a++) {
                        int new_j = min(j + int(ceil((j+x))), m);
                        if (new_result[new_j] == -1) {
                            new_result[new_j] = i+1;
                        }
                    }
                }
            }
        } else {
            for (int j = 0; j <= m; j++) {
                if (result[j] != -1) {
                    for (int a = 0; a <= yi; a++) {
                        int new_j = min(int(ceil(j*x)), m);
                        if (new_result[new_j] == -1) {
                            new_result[new_j] = i+1;
                        }
                    }
                }
            }
        }

        result = new_result;
    }

    for (int i = 1; i <= m; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}