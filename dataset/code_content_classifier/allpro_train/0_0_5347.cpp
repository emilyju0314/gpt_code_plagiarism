#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> min_card(N+1, 0);
    vector<int> max_card(N+1, N);

    for (int i = 0; i < M; i++) {
        int L, R;
        cin >> L >> R;
        min_card[R] = max(min_card[R], L);
        max_card[L] = min(max_card[L], R);
    }

    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (min_card[i] <= max_card[i]) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}