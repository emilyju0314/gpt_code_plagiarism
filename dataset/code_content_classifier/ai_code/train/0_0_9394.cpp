#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> sequence(n);
    for(int i = 0; i < n; i++){
        cin >> sequence[i];
    }
    
    int q;
    cin >> q;
    
    while(q--){
        int xi;
        cin >> xi;
        
        int result = 0;
        for(int l = 0; l < n; l++){
            int cur_gcd = sequence[l];
            for(int r = l; r < n; r++){
                cur_gcd = gcd(cur_gcd, sequence[r]);
                if(cur_gcd == xi){
                    result++;
                }
            }
        }
        
        cout << result << endl;
    }
    
    return 0;
}