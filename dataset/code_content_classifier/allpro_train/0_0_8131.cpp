#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> times(N);
    for(int i = 0; i < N; i++) {
        cin >> times[i];
    }
    
    sort(times.begin(), times.end());
    
    int sum = 0;
    int carry_time = 0;
    for(int i = 0; i < N; i++) {
        carry_time += times[i];
        sum += carry_time;
    }
    
    cout << sum << endl;
    
    return 0;
}