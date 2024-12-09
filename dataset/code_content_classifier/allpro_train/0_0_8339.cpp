#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<long long> costs(n);
        for(int i = 0; i < n; i++) {
            cin >> costs[i];
        }

        long long sum = 0;
        long long min_cost = costs[0];
        long long min_length = costs[0];
        for(int i = 1; i < n; i++) {
            min_length = min(min_length, costs[i]);
            sum += min_length * (n-i);
            min_cost = min(min_cost, sum + (n-i)*costs[i]);
        }

        cout << min_cost << endl;
    }

    return 0;
}