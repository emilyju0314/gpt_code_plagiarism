#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canFinishCoursework(int n, int m, vector<int>& caffeineDosages) {
    sort(caffeineDosages.begin(), caffeineDosages.end(), greater<int>());
    
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += max(0, caffeineDosages[i] - i);
        if(sum >= m) {
            return true;
        }
    }
    
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> caffeineDosages(n);
    for(int i = 0; i < n; i++) {
        cin >> caffeineDosages[i];
    }
    
    if(!canFinishCoursework(n, m, caffeineDosages)) {
        cout << -1 << endl;
        return 0;
    }
    
    long long left = 1, right = n;
    long long ans = n;
    while(left <= right) {
        long long mid = (left + right) / 2;
        if(canFinishCoursework(mid, m, caffeineDosages)) {
            right = mid - 1;
            ans = min(ans, mid);
        } else {
            left = mid + 1;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}