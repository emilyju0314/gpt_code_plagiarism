#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    int N, Q, caseNum = 1;

    while (cin >> N >> Q) {
        if (N == 0 && Q == 0) {
            break;
        }

        vector<int> marbles(N);
        for (int i = 0; i < N; i++) {
            cin >> marbles[i];
        }

        sort(marbles.begin(), marbles.end());

        cout << "CASE# " << caseNum << ":" << endl;
        for (int i = 0; i < Q; i++) {
            int query;
            cin >> query;

            auto it = lower_bound(marbles.begin(), marbles.end(), query);
            if (it != marbles.end() && *it == query) {
                cout << query << " found at " << distance(marbles.begin(), it) + 1 << endl;
            }
            else {
                cout << query << " not found" << endl;
            }
        }

        caseNum++;
    }

    return 0;
}