#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (m > n * (n - 1) / 2) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> scores(n, 1);
    int count = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (count == m) {
                break;
            }
            scores[i] += scores[j];
            count++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;

    return 0;
}