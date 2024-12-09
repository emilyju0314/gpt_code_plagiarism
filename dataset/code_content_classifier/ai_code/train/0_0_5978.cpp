#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> scores(n);
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        scores[i] = {a, b};
    }

    int max_draws = 0;
    int current_draws = 0;
    int prev_a = 0, prev_b = 0;

    for(int i = 0; i < n; i++) {
        int a = scores[i].first;
        int b = scores[i].second;

        int diff_a = a - prev_a;
        int diff_b = b - prev_b;

        current_draws += min(diff_a, diff_b);

        max_draws = max(max_draws, current_draws);

        prev_a = a;
        prev_b = b;
    }

    cout << max_draws + 1 << endl;

    return 0;
}