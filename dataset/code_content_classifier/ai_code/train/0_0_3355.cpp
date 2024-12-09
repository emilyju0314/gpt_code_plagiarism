#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> integers(N);
    for(int i=0; i<N; i++) {
        cin >> integers[i];
    }
    
    sort(integers.begin(), integers.end());
    
    long long sum = abs(integers[N-1] - integers[0]);
    for(int i=1; i<N-1; i++) {
        sum += max(abs(integers[i+1] - integers[i]), abs(integers[i] - integers[i-1]));
    }
    
    cout << sum << endl;
    
    return 0;
}