#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * m; j++) {
            char window;
            cin >> window;
            if (window == '1') {
                count++;
                break;
            }
        }
    }

    cout << count << endl;

    return 0;
}