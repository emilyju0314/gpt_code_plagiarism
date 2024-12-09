#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Function to calculate the passing fee for Barney to cuddle from intersection v to u
long long calculatePassingFee(vector<long long>& passingFees, long long v, long long u) {
    long long fee = 0;
    while (v != u) {
        if (v > u) {
            swap(v, u);
        }
        fee += passingFees[u];
        u /= 2;
    }
    return fee;
}

int main() {
    int q;
    cin >> q;

    vector<long long> passingFees(1024, 0); // Initialize passing fees for all roads

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            long long v, u, w;
            cin >> v >> u >> w;

            while (v != u) {
                if (v > u) {
                    swap(v, u);
                }
                passingFees[u] += w;
                u /= 2;
            }
        } else {
            long long v, u;
            cin >> v >> u;

            long long fee = calculatePassingFee(passingFees, v, u);
            cout << fee << endl;
        }
    }

    return 0;
}