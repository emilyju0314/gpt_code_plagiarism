#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> visitors(n);
    vector<int> revenue(n);
    
    for (int i = 0; i < n; i++) {
        cin >> visitors[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> revenue[i];
    }
    
    vector<pair<int, int>> potential;
    
    for (int i = 0; i < n; i++) {
        int max_visitors = visitors[i];
        int min_revenue = revenue[i];
        for (int j = i; j < n; j++) {
            max_visitors = max(max_visitors, visitors[j]);
            min_revenue = min(min_revenue, revenue[j]);
            potential.push_back({max_visitors * 100, min_revenue});
        }
    }
    
    sort(potential.begin(), potential.end());
    
    long long total_grade = 0;
    
    for (int i = 0; i < k; i++) {
        total_grade += potential[i].second;
    }
    
    double expected_grade = total_grade / (double)k;
    
    cout << fixed;
    cout.precision(7);
    cout << expected_grade << endl;
    
    return 0;
}