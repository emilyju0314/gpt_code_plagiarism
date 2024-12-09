#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, w, k;
    cin >> n >> w >> k;
    
    vector<int> a(n), t(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }
    
    long long totalPleasure = 0;
    
    for(int i = 0; i < n; i++) {
        long long pleasure = 0;
        long long timeLeft = k;
        
        for(int j = i; j < n; j++) {
            if(timeLeft <= 0) {
                break;
            }
            
            if(j != i) {
                timeLeft -= t[j-1];
            }
            
            if(timeLeft <= 0) {
                break;
            }
            
            if(j < n-1 && timeLeft - t[j] / 2 >= 0) {
                timeLeft -= t[j] / 2;
                pleasure += a[j];
                w--;
            } else {
                timeLeft -= t[j];
                pleasure += a[j];
            }
        }
        
        totalPleasure = max(totalPleasure, pleasure);
    }
    
    cout << totalPleasure << endl;
    
    return 0;
}