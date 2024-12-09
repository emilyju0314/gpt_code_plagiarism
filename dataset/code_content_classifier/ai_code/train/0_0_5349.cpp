#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<long long>& a, vector<long long>& b) {
    return abs(a[0]) + abs(a[1]) + abs(a[2]) > abs(b[0]) + abs(b[1]) + abs(b[2]);
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<long long>> cakes(N, vector<long long>(3));

    for (int i = 0; i < N; i++) {
        cin >> cakes[i][0] >> cakes[i][1] >> cakes[i][2];
    }

    sort(cakes.begin(), cakes.end(), compare);

    long long ans = 0;
    for (int i = 0; i < (1 << 3); i++) {
        int count[3] = {0};
        long long val = 0;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 3; k++) {
                if ((1 << k) & i) {
                    count[k]++;
                }
            }
            if (count[0] <= M && count[1] <= M && count[2] <= M) {
                val = max(val, abs(cakes[j][0] + cakes[j][1] + cakes[j][2]));
            }
        }
        ans = max(ans, val);
    }

    cout << ans << endl;

    return 0;
}