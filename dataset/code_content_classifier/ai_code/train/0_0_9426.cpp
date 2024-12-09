#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int W, H;
    cin >> W >> H;

    vector<int> p(W);
    for (int i = 0; i < W; i++) {
        cin >> p[i];
    }

    vector<int> q(H);
    for (int j = 0; j < H; j++) {
        cin >> q[j];
    }

    sort(p.begin(), p.end(), greater<int>());
    sort(q.begin(), q.end(), greater<int>());

    int cost = 0;
    int h_count = 1, v_count = 1;

    for (int i = 0, j = 0; i < W && j < H;) {
        if (p[i] >= q[j]) {
            cost += p[i] * v_count;
            h_count++;
            i++;
        } else {
            cost += q[j] * h_count;
            v_count++;
            j++;
        }
    }

    while (i < W) {
        cost += p[i] * v_count;
        i++;
    }

    while (j < H) {
        cost += q[j] * h_count;
        j++;
    }

    cout << cost << endl;

    return 0;
}