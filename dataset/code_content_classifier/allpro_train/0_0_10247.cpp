#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    long long x;
    cin >> n >> k >> x;
    
    vector<long long> levels(n);
    for(int i = 0; i < n; i++) {
        cin >> levels[i];
    }
    
    sort(levels.begin(), levels.end());
    
    vector<long long> diffs;
    for(int i = 1; i < n; i++) {
        long long diff = levels[i] - levels[i-1];
        if(diff > x) {
            diffs.push_back(diff);
        }
    }
    
    sort(diffs.begin(), diffs.end());
    
    int groups = diffs.size() + 1;
    
    for(int i = 0; i < diffs.size(); i++) {
        long long needed = (diffs[i] - 1) / x;
        if(k >= needed) {
            k -= needed;
            groups--;
        } else {
            break;
        }
    }
    
    cout << groups << endl;
    
    return 0;
}