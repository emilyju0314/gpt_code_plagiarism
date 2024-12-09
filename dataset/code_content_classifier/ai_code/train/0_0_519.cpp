#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const uint64_t MOD = 1ULL << 58;

int main() {
    int n;
    cin >> n;
    
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin >> x[i];
    }
    
    vector<uint64_t> count(MOD);
    for(auto xi : x){
        count[xi]++;
    }
    
    vector<uint64_t> result(n);
    for(uint64_t i=0; i<n; i++){
        uint64_t sum = 0;
        for(uint64_t j=0; j<MOD; j++){
            sum += count[j] * count[(i-j)%MOD] % MOD;
        }
        result[i] = sum % MOD;
    }
    
    for(auto res : result){
        cout << res << endl;
    }
    
    return 0;
}