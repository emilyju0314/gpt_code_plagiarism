#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int min_sum = INT_MAX;

    for (int bit = 0; bit < (1 << (N-1)); bit++) {
        vector<int> cards = A;
        int sum = 0;

        for (int i = 0; i < N-1; i++) {
            if (bit & (1 << i)) {
                sum += cards[i] + cards[i+1];
                cards[i+1] = 0;
            }
        }

        int temp_sum = 0;
        for (int num : cards) {
            temp_sum += num;
        }

        min_sum = min(min_sum, sum + temp_sum);
    }

    cout << min_sum << endl;

    return 0;
}