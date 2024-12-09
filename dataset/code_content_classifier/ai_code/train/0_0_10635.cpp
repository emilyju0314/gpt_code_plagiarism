#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> cards(N);
    unordered_map<int, int> freq;

    for(int i = 0; i < N; i++) {
        cin >> cards[i];
        freq[cards[i] % M]++;
    }

    int pairs = freq[0] / 2;
    for(int i = 1; i <= M/2; i++) {
        int j = M - i;
        int count_i = freq[i];
        int count_j = freq[j];

        if(i < j) {
            pairs += min(count_i, count_j);
            int diff = abs(count_i - count_j);
            if(diff > 0) {
                int min_diff = min(diff, freq[0]);
                pairs += min_diff;
                freq[0] -= min_diff;
                pairs += diff - min_diff;
            }
        } else if(i == j) {
            pairs += count_i / 2;
        }
    }

    cout << pairs << endl;

    return 0;
}