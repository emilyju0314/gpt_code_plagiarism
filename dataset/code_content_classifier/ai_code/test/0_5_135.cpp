#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMinimumScore(vector<int>& a, int k) {
    sort(a.begin(), a.end());
    int n = a.size();
    int score = 0;
    
    for(int i=0; i<k; i++) {
        int ai = a[i];
        int aj = a[n-1-i];
        score += ai / aj;
    }
    
    for(int i=k; i<n-k; i++) {
        score += a[i];
    }
    
    return score;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n);
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        
        cout << getMinimumScore(a, k) << endl;
    }
    
    return 0;
}