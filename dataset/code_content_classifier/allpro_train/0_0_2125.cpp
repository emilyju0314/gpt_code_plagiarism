#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> limit(n);
    for(int i = 0; i < n; i++) {
        cin >> limit[i];
    }
    
    sort(limit.begin(), limit.end(), greater<int>());
    
    int prev_occurrences = limit[0], max_length = limit[0];
    for(int i = 1; i < n; i++) {
        prev_occurrences = max(0, min(prev_occurrences - 1, limit[i]));
        max_length += prev_occurrences;
    }
    
    cout << max_length << endl;
    
    return 0;
}