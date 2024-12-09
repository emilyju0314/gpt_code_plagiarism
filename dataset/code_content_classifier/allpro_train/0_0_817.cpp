#include <iostream>

using namespace std;

int main() {
    int n, k, d;
    cin >> n >> k >> d;

    if (n > k) {
        cout << -1 << endl;
        return 0;
    }

    int buses[1000][1000] = {0};

    int day = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            buses[i][j] = day;
            day++;
            if (day > k) {
                day = 1;
            }
        }
    }

    for (int i = 0; i < d; i++) {
        for (int j = 0; j < n; j++) {
            cout << buses[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}