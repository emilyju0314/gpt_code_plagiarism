#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    
    vector<int> balances(n);
    for(int i = 0; i < n; i++) {
        cin >> balances[i];
    }
    
    cin >> q;
    while(q--) {
        int event;
        cin >> event;
        
        if(event == 1) {
            int p, x;
            cin >> p >> x;
            balances[p-1] = x;
        } else if(event == 2) {
            int x;
            cin >> x;
            for(int i = 0; i < n; i++) {
                if(balances[i] < x) {
                    balances[i] = x;
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << balances[i] << " ";
    }
    
    return 0;
}