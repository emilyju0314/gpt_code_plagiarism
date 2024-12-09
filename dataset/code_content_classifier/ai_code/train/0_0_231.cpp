#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> a(N);
    for(int i=0; i<N; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    long long max_f = 0;
    for(int i=0; i<N-1; i++) {
        max_f += a[i] - 1;
    }
    
    cout << max_f << endl;
    
    return 0;
}