#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> initial(m);
    for(int i = 0; i < m; i++) {
        cin >> initial[i];
    }
    
    sort(initial.begin(), initial.end());
    
    long long int result = 1;
    
    for(int i = 1; i < m; i++) {
        result = (result * (initial[i] - initial[i-1] - 1)) % MOD;
    }
    
    if(initial[0] != 1) {
        result = (result * (initial[0] - 1)) % MOD;
    }
    
    if(initial[m-1] != n) {
        result = (result * (n - initial[m-1])) % MOD;
    }
    
    cout << result << endl;
    
    return 0;
}