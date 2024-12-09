#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> exams;
    
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        exams.push_back(make_pair(a, b));
    }
    
    sort(exams.begin(), exams.end());
    
    int minDay = exams[0].first;
    
    for (int i = 0; i < n; i++) {
        if (minDay < exams[i].first) {
            minDay = exams[i].first;
        } else {
            minDay = exams[i].second;
        }
    }
    
    cout << minDay << endl;
    
    return 0;
}