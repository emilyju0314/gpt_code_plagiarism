#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        vector<pair<int, pair<int, int>>> operations;
        
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += a[i];
        }
        
        if(sum % n != 0) {
            cout << "-1" << endl;
            continue;
        }
        
        int avg = sum / n;
        for(int i = 0; i < n; i++) {
            while(a[i] > avg) {
                for(int j = n-1; j > i; j--) {
                    if(a[j] < avg) {
                        int diff = min(a[i] - avg, avg - a[j]);
                        a[i] -= diff;
                        a[j] += diff;
                        operations.push_back({i+1, {j+1, diff}});
                        break;
                    }
                }
            }
        }
        
        cout << operations.size() << endl;
        for(auto op : operations) {
            cout << op.first << " " << op.second.first << " " << op.second.second << endl;
        }
    }
    
    return 0;
}