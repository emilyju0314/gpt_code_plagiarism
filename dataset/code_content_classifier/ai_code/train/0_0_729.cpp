#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Parcel {
    int in_time, out_time, weight, strength, value;
};

int main() {
    int n, S;
    cin >> n >> S;

    vector<Parcel> parcels(n);
    for(int i = 0; i < n; i++) {
        cin >> parcels[i].in_time >> parcels[i].out_time >> parcels[i].weight >> parcels[i].strength >> parcels[i].value;
    }

    sort(parcels.begin(), parcels.end(), [](const Parcel& a, const Parcel& b) {
        return a.out_time < b.out_time;
    });

    vector<vector<int>> dp(2 * n, vector<int>(S + 1, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < S + 1; j++) {
            dp[parcels[i].out_time][j] = max(dp[parcels[i].out_time][j], dp[parcels[i].in_time][j]);
            if(j >= parcels[i].weight && j + parcels[i].strength <= S) {
                dp[parcels[i].out_time][j + parcels[i].strength] = max(dp[parcels[i].out_time][j + parcels[i].strength], dp[parcels[i].in_time][j] + parcels[i].value);
            }
        }
    }

    int max_value = 0;
    for(int i = 0; i < 2 * n; i++) {
        for(int j = 0; j <= S; j++) {
            max_value = max(max_value, dp[i][j]);
        }
    }

    cout << max_value << endl;

    return 0;
}