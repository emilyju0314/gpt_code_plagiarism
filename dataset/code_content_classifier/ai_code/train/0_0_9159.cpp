#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> operations;

    for (int i = 0; i < N; i++) {
        if (a[i] < 0) {
            for (int j = N - 1; j > i; j--) {
                operations.push_back({j + 1, j});
                a[j] += a[j + 1];
            }
        } else {
            for (int j = 0; j < i; j++) {
                operations.push_back({j + 1, j + 1});
            }
        }
    }

    cout << operations.size() << endl;
    for (auto op : operations) {
        cout << op.first << " " << op.second << endl;
    }

    return 0;
}