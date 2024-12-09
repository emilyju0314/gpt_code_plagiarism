#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    unordered_map<long long, int> prefix_sums;
    long long prefix_sum = 0;
    long long ans = 0;
    
    prefix_sums[0]++;
    
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        
        prefix_sum += A;
        ans += prefix_sums[prefix_sum];
        prefix_sums[prefix_sum]++;
    }
    
    cout << ans << endl;
    
    return 0;
}