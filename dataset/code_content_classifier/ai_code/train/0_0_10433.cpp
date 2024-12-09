#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> sticks(n);
    for(int i = 0; i < n; i++) {
        cin >> sticks[i];
    }

    sort(sticks.begin(), sticks.end());

    long long total_area = 0;
    for(int i = 0; i < n; i += 2) {
        if(i+1 < n && sticks[i] == sticks[i+1]) {
            total_area += (long long)sticks[i] * sticks[i];
        }
    }

    cout << total_area << endl;

    return 0;
}