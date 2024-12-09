#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long pos = 0, neg = 0;
    for(int i = 0; i < n; i++) {
        pos += a[i];
        neg += a[i];
        a[i] < 0 ? a[i] = -1 : a[i] = 1;
    }
    
    if(pos * neg > 0) {
        long long ans = min(abs(pos), abs(neg));
        cout << ans * 2 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}