#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<int> heights(n);
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    long long max_days = 1e18;
    for(int d = 1; d <= max_days; d++) {
        long long total_cut_length = 0;
        for(int i = 0; i < n; i++) {
            long long growth = d * i - heights[i];
            if(growth > 0) {
                total_cut_length += growth;
            }
            if(total_cut_length > k) {
                break;
            }
        }

        if(total_cut_length <= k) {
            cout << d << endl;
            break;
        }
    }

    return 0;
}