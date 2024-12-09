#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    sort(points.begin(), points.end());
    
    vector<long long> count(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (points[j].second > points[i].second) {
                count[j]++;
            } else {
                break;
            }
        }
    }
    
    long long result = 0;
    for (int i = 0; i < n; i++) {
        result += (count[i] * (count[i] + 1)) / 2;
    }
    
    cout << result << endl;
    
    return 0;
}