#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int x = 0;
        if(m <= k) {
            for(int i = 0; i <= min(m, k); i++) {
                int min_element = INT_MAX;
                for(int j = 0; j <= k - i; j++) {
                    int max_element = 0;
                    for(int l = 0; l < i; l++) {
                        max_element = max(max_element, min(a[j+l], a[n-1-(i-l-1)]));
                    }
                    min_element = min(min_element, max_element);
                }
                x = max(x, min_element);
            }
        } else {
            x = min(a[m - 1], *max_element(a.begin(), a.end()));
        }

        cout << x << endl;
    }

    return 0;
}