#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, w, q;
    cin >> n >> w >> q;

    vector<int> x(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<int> k(q);
    for(int i = 0; i < q; i++) {
        cin >> k[i];
    }

    vector<int> cuts(q, 0);
    vector<int> maxLeft(n, 0);
    vector<int> minRight(n, 0);

    int maxVal = 0;
    for(int i = 0; i < n; i++) {
        maxVal = max(maxVal, x[i]);
        maxLeft[i] = maxVal;
    }

    maxVal = x[n-1];
    minRight[n-1] = x[n-1];
    for(int i = n-2; i >= 0; i--) {
        maxVal = max(maxVal, x[i]);
        minRight[i] = maxVal;
    }

    for(int i = 0; i < n-1; i++) {
        if(maxLeft[i] <= minRight[i+1]-w) {
            cuts[0]++;
        }
    }

    sort(x.begin(), x.end());
    for(int i = 1; i < q; i++) {
        cuts[i] = cuts[i-1];
        if(x[0] + w < x[n-1]) {
            cuts[i]++;
        }

        cout << cuts[i-1] << endl;
    }

    cout << cuts[q-1] << endl;
    
    return 0;
}