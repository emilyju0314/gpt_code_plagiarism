#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for(int i=0; i<n; i++) {
            cin >> p[i];
        }

        vector<int> ans(n);
        int maxValue = 0;
        for(int i=0; i<n; i++) {
            ans[i] = p[i];
            if(p[i] > maxValue) {
                maxValue = p[i];
            } else {
                ans[i] = -p[i];
            }
        }

        // Check if the array is bipartite
        bool isBipartite = true;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(i < j && ans[i] > ans[j]) {
                    isBipartite = false;
                    break;
                }
            }
            if(!isBipartite) {
                break;
            }
        }

        // Print result
        if(isBipartite) {
            cout << "YES" << endl;
            for(int i=0; i<n; i++) {
                cout << ans[i] << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}