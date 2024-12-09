#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == i+1) {
            ans++;
        }
    }

    for(int i = 0; i < n; i++) {
        if(a[i] != i+1 && a[a[i]-1] == i+1) {
            ans = max(ans, 2);
        }
    }

    cout << ans << endl;

    return 0;
}