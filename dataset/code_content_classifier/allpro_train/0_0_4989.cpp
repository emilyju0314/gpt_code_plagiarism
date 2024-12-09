#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int K;
    cin >> K;

    set<int> ranks;
    for (int i = 0; i < K; i++) {
        int rank;
        cin >> rank;
        ranks.insert(rank);
    }

    int min_declined = 0;
    int expected_rank = 1;

    for (auto it = ranks.begin(); it != ranks.end(); it++) {
        min_declined += (*it - expected_rank);
        expected_rank = *it + 1;
    }

    min_declined += (25 - ranks.size());

    cout << min_declined << endl;

    return 0;
}