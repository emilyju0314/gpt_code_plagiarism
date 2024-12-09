#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<string> picture(n);
    for (int i = 0; i < n; i++) {
        cin >> picture[i];
    }

    int num_repaint = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            int k = i;
            while (k < n && picture[k][j] == picture[i][j]) {
                k++;
            }
            int len = k - i;

            if (len > y) {
                num_repaint += y;
                i = k - 1;
            } else {
                num_repaint += len;
                i = k - 1;
            }
        }
    }

    cout << num_repaint << endl;

    return 0;
}