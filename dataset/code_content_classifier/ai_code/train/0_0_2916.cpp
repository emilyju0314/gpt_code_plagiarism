#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    int x = 0;
    for (int i = 0; i < N; i += 2) {
        x ^= a[i];
    }
    
    vector<int> ans(N);
    ans[0] = x;
    
    for (int i = 1; i < N; i++) {
        ans[i] = a[i - 1] ^ ans[i - 1];
    }
    
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}