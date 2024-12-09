#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<int> t(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    
    vector<pair<int, int>> category_time_pairs;
    
    for (int i = 0; i < n; i++) {
        category_time_pairs.push_back(make_pair(a[i], t[i]));
    }
    
    sort(category_time_pairs.begin(), category_time_pairs.end());
    
    long long total_time = 0;
    long long current_time = 0;
    
    for (int i = 0; i < n; i++) {
        if (i > 0 && category_time_pairs[i].first == category_time_pairs[i-1].first) {
            total_time += current_time;
        } else {
            total_time += category_time_pairs[i].second;
            current_time = category_time_pairs[i].second;
        }
    }
    
    cout << total_time << endl;
    
    return 0;
}