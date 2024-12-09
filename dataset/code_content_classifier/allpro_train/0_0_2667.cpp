#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, Z, W;
    cin >> N >> Z >> W;
    
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    if (N == 1) {
        cout << abs(a[0] - W) << endl;
        return 0;
    }
    
    int ans = 0;
    ans = max(ans, abs(a[N-1] - a[N-2]));
    if (N > 2) {
        ans = max(ans, abs(a[N-1] - *max_element(a.begin(), a.end()-2)));
    }
    
    cout << ans << endl;
    
    return 0;
}