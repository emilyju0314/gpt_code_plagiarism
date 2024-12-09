#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> responsibility(n);
    vector<int> age(n);
    
    for (int i = 0; i < n; i++) {
        cin >> responsibility[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> age[i];
    }
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        
        x--; y--;
        
        int max_group_size = 0;
        
        if (abs(age[x] - age[y]) <= k && responsibility[x] >= responsibility[y]) {
            max_group_size = 2;
            for (int j = 0; j < n; j++) {
                if (j == x || j == y) continue;
                if (abs(age[x] - age[j]) <= k && responsibility[j] >= responsibility[y]) {
                    max_group_size++;
                }
            }
        }
        
        cout << max_group_size << endl;
    }
    
    return 0;
}