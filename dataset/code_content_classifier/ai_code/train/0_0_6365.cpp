#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> ranks(n);
    for (int i = 0; i < n; i++) {
        cin >> ranks[i];
    }

    int total_coins = 0;
    while (*max_element(ranks.begin(), ranks.end()) < k) {
        int max_rank_index = max_element(ranks.begin(), ranks.end()) - ranks.begin();
        ranks[max_rank_index] = k;
        total_coins++;

        for (int i = 0; i < n; i++) {
            if (ranks[i] < k) {
                ranks[i]++;
            }
        }
    }

    cout << total_coins << endl;

    return 0;
}