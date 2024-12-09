#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> dishes(n);
    for (int i = 0; i < n; i++) {
        cin >> dishes[i];
    }

    int bowls_needed = 0;
    int plates_needed = 0;

    for (int i = 0; i < n; i++) {
        if (dishes[i] == 1) {
            if (m > 0) {
                m--;
            } else {
                bowls_needed++;
            }
        } else {
            if (m > 0 && k > 0) {
                if (m > k) {
                    m--;
                } else {
                    k--;
                }
            } else if (m > 0) {
                m--;
            } else if (k > 0) {
                k--;
            } else {
                plates_needed++;
            }
        }
    }

    cout << (bowls_needed + plates_needed) << endl;

    return 0;
}