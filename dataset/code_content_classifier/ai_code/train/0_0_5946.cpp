#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> colors(N);
    for (int i = 0; i < N; i++) {
        cin >> colors[i];
    }

    for (int q = 0; q < Q; q++) {
        int l, r;
        cin >> l >> r;

        set<int> uniqueColors;
        for (int i = l-1; i < r; i++) {
            uniqueColors.insert(colors[i]);
        }

        cout << uniqueColors.size() << endl;
    }

    return 0;
}