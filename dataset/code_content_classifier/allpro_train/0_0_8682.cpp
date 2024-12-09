#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    vector<vector<int>> chefLists(n+1);
    for(int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        chefLists[i].resize(c);
        for(int j = 0; j < c; j++) {
            cin >> chefLists[i][j];
        }
    }
    
    int q;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        int type;
        cin >> type;
        
        if(type == 1) {
            int k, l, r;
            cin >> k >> l >> r;
            
            long long sum = 0;
            for(int day = 1; day <= k; day++) {
                vector<int> new_a(n+1);
                for(int j = 1; j <= n; j++) {
                    if(day == 1) {
                        new_a[j] = a[j];
                    } else {
                        new_a[j] = (long long)j * a[j] % MOD;
                    }
                }
                
                for(int j = 1; j <= n; j++) {
                    for(int copyChef : chefLists[j]) {
                        new_a[j] = (new_a[j] + new_a[copyChef]) % MOD;
                    }
                }
                
                swap(a, new_a);
            }
            
            for(int j = l; j <= r; j++) {
                sum = (sum + a[j]) % MOD;
            }
            
            cout << sum << endl;
        } else {
            int chef, x;
            cin >> chef >> x;
            a[chef] = (a[chef] + x) % MOD;
        }
    }
    
    return 0;
}