#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> x(N);
    for(int i = 0; i < N; i++) {
        cin >> x[i];
    }

    int min_time = 1e9;
    for(int i = 0; i <= N-K; i++) {
        int left_candle = x[i];
        int right_candle = x[i+K-1];
        int time = min(abs(left_candle) + abs(left_candle - right_candle), abs(right_candle) + abs(left_candle - right_candle));
        min_time = min(min_time, time);
    }

    cout << min_time << endl;
    
    return 0;
}