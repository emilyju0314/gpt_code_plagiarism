#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> permutation(N);
    for(int i=0; i<N; i++) {
        cin >> permutation[i];
    }
    
    long long ans = 0;
    for(int i=0; i<N-1; i++) {
        ans += abs(permutation[i] - permutation[i+1]);
    }
    ans += permutation[0] + permutation[N-1];
    
    cout << ans << endl;
    
    return 0;
}