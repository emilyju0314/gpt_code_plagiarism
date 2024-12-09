#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    sort(points.begin(), points.end());

    unordered_map<int, int> count;
    for(int i = 0; i < n; i++) {
        count[points[i].second]++;
    }

    long long result = 0;
    long long sum = 0;
    for(auto it = count.rbegin(); it != count.rend(); it++) {
        sum += it->second;
        result += sum;
    }

    cout << result << endl;

    return 0;
}