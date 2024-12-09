#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MOD 1000000007

struct Box {
    int pos;
    int weight;
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<Box> boxes(n);
    for (int i = 0; i < n; i++) {
        cin >> boxes[i].pos;
    }

    for (int i = 0; i < n; i++) {
        cin >> boxes[i].weight;
    }

    vector<long long> prefix_sum(n);
    prefix_sum[0] = 0;
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + (boxes[i].pos - boxes[i - 1].pos) * boxes[i - 1].weight;
    }

    while (q--) {
        int x, y;
        cin >> x >> y;

        if (x < 0) {
            // Update weight of box
            int id = -x;
            boxes[id - 1].weight = y;
            continue;
        }

        int l = x - 1, r = y - 1;
        long long energy = prefix_sum[r] - (l > 0 ? prefix_sum[l-1] : 0);
        cout << energy % MOD << endl;
    }

    return 0;
}