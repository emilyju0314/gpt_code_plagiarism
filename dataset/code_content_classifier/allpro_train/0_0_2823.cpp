#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    vector<string> keyboard(n);
    int shiftX = -1, shiftY = -1;
    for (int i = 0; i < n; i++) {
        cin >> keyboard[i];
        for (int j = 0; j < m; j++) {
            if (keyboard[i][j] == 'S') {
                shiftX = i;
                shiftY = j;
            }
        }
    }

    int q;
    cin >> q;
    string text;
    cin >> text;

    int count = 0;
    for (char c : text) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (tolower(c) == keyboard[i][j] || toupper(c) == keyboard[i][j]) {
                    if (shiftX != -1 && sqrt(pow(i - shiftX, 2) + pow(j - shiftY, 2)) <= x) {
                        found = true;
                    } else if (isupper(c)) {
                        count++;
                        found = true;
                    }
                }
            }
        }
        if (!found) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << count << endl;

    return 0;
}