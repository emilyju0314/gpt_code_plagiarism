#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    long long C;
    cin >> n >> C;

    vector<long long> w(n-2);
    for(int i = 0; i < n-2; i++) {
        cin >> w[i];
    }

    vector<long long> h(n, -1);
    h[0] = 0;
    h[1] = w[0];
    h[n-1] = w[n-3];
    long long sum_diff = 0;
    for(int i = 0; i < n-2; i++) {
        sum_diff += w[i];
    }

    // Determine the potential heights
    long long potential_sum = C + h[1] + h[n-1];
    if(potential_sum <= sum_diff) {
        cout << "NO" << endl;
        return 0;
    }
    h[n-2] = potential_sum - sum_diff;

    // Check if the calculated heights are valid
    for(int i = 1; i < n-2; i++) {
        if(h[i] == -1) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    for(int i = 0; i < n; i++) {
        cout << h[i] << " ";
    }
    cout << endl;

    return 0;
}