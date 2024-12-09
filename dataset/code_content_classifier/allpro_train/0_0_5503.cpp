#include <iostream>
using namespace std;

const int MOD = 1e6 + 3;

int main() {
    int C, W, H;
    cin >> C >> W >> H;
    
    long long ans = 1; // Start with 1 to account for the case where there are no bricks in any columns
    
    for(int i = 1; i <= C; i++) {
        if(i > W) {
            ans = (ans * 2) % MOD; // Every segment is wider than W bricks
        }
    }
    
    for(int j = 1; j <= C; j++) {
        if(j > H) {
            ans = (ans * 2) % MOD; // Every column is higher than H bricks
        }
    }
    
    cout << (ans - 2 + MOD) % MOD << endl;
    
    return 0;
}