#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int K, N;
    cin >> K >> N;
    
    vector<int> times(N);
    for (int i = 0; i < N; i++) {
        cin >> times[i];
    }
    
    sort(times.begin(), times.end());
    
    int minTime = INT_MAX;
    for (int i = 0; i <= N - 2*K; i++) {
        minTime = min(minTime, times[i + 2*K - 1] - times[i]);
    }
    
    cout << minTime << endl;
    
    return 0;
}