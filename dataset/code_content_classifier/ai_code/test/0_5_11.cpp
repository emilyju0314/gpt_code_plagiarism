#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for(int i=1; i<=n; i++) {
        int cnt = 0;
        for(int j=0; j<n; j++) {
            if(a[j] == i) {
                cnt++;
                break;
            }
        }
        if(cnt == 0) {
            ans++;
        }
    }

    cout << n - ans << endl;

    return 0;
}