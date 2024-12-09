#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n, s, m, k;
    cin >> n >> s >> m >> k;
    
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    vector<pair<int, int>> segments(s);
    for(int i=0; i<s; i++)
        cin >> segments[i].first >> segments[i].second;
    
    sort(a.begin(), a.end());
    
    vector<bool> covered(n, false);
    for(int i=0; i<s; i++) {
        for(int j=segments[i].first-1; j<=segments[i].second-1; j++)
            covered[j] = true;
    }
    
    vector<int> nums;
    for(int i=0; i<n; i++) {
        if(covered[i])
            nums.push_back(a[i]);
    }
    
    if((int)nums.size() < k)
        cout << -1 << endl;
    else {
        sort(nums.begin(), nums.end());
        cout << nums[k-1] << endl;
    }
    
    return 0;
}