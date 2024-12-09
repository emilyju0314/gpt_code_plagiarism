#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int max_res = INT_MIN;
    int delim0, delim1, delim2;
    
    for(int i = 0; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            for(int k = j; k <= n; k++) {
                int res = a[i] - a[j] + a[j] - a[k] + a[k] - a[n];
                if(res > max_res) {
                    max_res = res;
                    delim0 = i;
                    delim1 = j;
                    delim2 = k;
                }
            }
        }
    }
    
    cout << delim0 << " " << delim1 << " " << delim2 << endl;
    
    return 0;
}