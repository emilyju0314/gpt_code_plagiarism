#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> speeds(n);
    for(int i=0; i<n; i++) {
        cin >> speeds[i];
    }

    sort(speeds.begin(), speeds.end());

    long long min_sum = 0;
    for(int i=0; i<n; i++) {
        min_sum += abs(speeds[i] - speeds[n/2]);
    }

    cout << min_sum << endl;

    return 0;
}