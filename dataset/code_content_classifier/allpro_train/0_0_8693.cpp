#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> polygon(n);
    for (int i = 0; i < n; i++) {
        cin >> polygon[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (polygon[i][j] == '.') {
                int area = 0;
                for (int x = i; x < n; x++) {
                    for (int y = j; y < m; y++) {
                        if (polygon[x][y] == '.') {
                            area++;
                        } else {
                            break;
                        }

                        if (area > 0 && area <= 3) {
                            count++;
                        }
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}