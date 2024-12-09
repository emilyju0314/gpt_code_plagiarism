#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> coins(N);
    for(int i = 0; i < N; i++) {
        cin >> coins[i];
    }

    double ans = 0.0;

    for(int i = 0; i < N; i++) {
        double ratio = 1.0;
        for(int j = 0; j < N; j++) {
            if(i != j) {
                ratio = min(ratio, (double)coins[j] / coins[i]);
            }
        }
        ans = max(ans, ratio);
    }

    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}