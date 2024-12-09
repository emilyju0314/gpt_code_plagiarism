#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> broken_segments(n);
    for(int i=0; i<n; i++) {
        cin >> broken_segments[i];
    }

    vector<int> intervals;
    for(int i=1; i<n; i++) {
        intervals.push_back(broken_segments[i] - broken_segments[i-1] - 1);
    }

    sort(intervals.begin(), intervals.end(), greater<int>());

    int total_length = n;
    for(int i=0; i<k-1; i++) {
        total_length += intervals[i];
    }

    cout << total_length << endl;

    return 0;
}