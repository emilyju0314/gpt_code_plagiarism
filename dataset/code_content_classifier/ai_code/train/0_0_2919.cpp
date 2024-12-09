#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> jewels(N);
    for (int i = 0; i < N; i++) {
        cin >> jewels[i];
    }

    int max_sum = 0;

    for (int left_take = 0; left_take <= min(N, K); left_take++) {
        for (int right_take = 0; right_take <= min(N - left_take, K - left_take); right_take++) {
            vector<int> hand;

            for (int i = 0; i < left_take; i++) {
                hand.push_back(jewels[i]);
            }
            for (int i = N - right_take; i < N; i++) {
                hand.push_back(jewels[i]);
            }

            sort(hand.begin(), hand.end());

            int sum = 0;
            for (int i = 0; i < hand.size(); i++) {
                sum += hand[i];
            }

            int remaining_inserts = K - left_take - right_take;
            for (int i = 0; i < hand.size() && i < remaining_inserts && hand[i] < 0; i++) {
                sum -= hand[i];
            }

            max_sum = max(max_sum, sum);
        }
    }

    cout << max_sum << endl;

    return 0;
}