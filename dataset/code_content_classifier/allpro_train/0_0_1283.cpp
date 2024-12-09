#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> assignments(M);
    for (int i = 0; i < M; i++) {
        cin >> assignments[i];
    }

    int total_days = 0;
    for (int i = 0; i < M; i++) {
        total_days += assignments[i];
    }

    if (total_days > N) {
        cout << -1 << endl;
    } else {
        int hang_out_days = N - total_days;
        cout << hang_out_days << endl;
    }

    return 0;
}