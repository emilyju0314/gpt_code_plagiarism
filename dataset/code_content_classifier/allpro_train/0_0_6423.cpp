#include <iostream>
#define MOD 998244353
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Calculate total number of integers with n digits
    long long total = 10;
    long long ans = 10;
    for(int i=2;i<=n;++i){
        ans = (ans*10)%MOD;
        total = (total + ans)%MOD;
    }

    // Calculate number of blocks of length i for each i from 1 to n
    long long blocks[n];
    blocks[0] = total;
    for(int i=1;i<n;++i){
        blocks[i] = (10*blocks[i-1])%MOD;
    }

    // Print the results
    for(int i=0;i<n;++i){
        cout << blocks[i] << " ";
    }

    return 0;
}