#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int a, b, p;
        cin >> a >> b >> p;
        
        string s;
        cin >> s;
        
        int n = s.size();
        vector<long long> costs(n);
        costs[n-1] = 0;
        
        for (int i = n-2; i >= 0; i--) {
            if (s[i] == s[i+1]) {
                costs[i] = costs[i+1];
            } else if (s[i] == 'A') {
                costs[i] = a + costs[i+1];
            } else {
                costs[i] = b + costs[i+1];
            }
        }
        
        int i = 1;
        while (i < n && costs[i] <= p) {
            i++;
        }
        
        cout << i << endl;
    }
    
    return 0;
}