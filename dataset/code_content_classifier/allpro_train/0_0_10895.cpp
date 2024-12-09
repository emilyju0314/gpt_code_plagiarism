#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, C, K;
    cin >> N >> C >> K;
    
    vector<int> arrivalTimes(N);
    for(int i=0; i<N; i++) {
        cin >> arrivalTimes[i];
    }
    
    sort(arrivalTimes.begin(), arrivalTimes.end());
    
    int buses = 0;
    int index = 0;
    
    while(index < N) {
        int departureTime = arrivalTimes[index] + K;
        buses++;
        
        int passengersOnBus = 1;
        while(passengersOnBus < C && index+passengersOnBus < N && arrivalTimes[index+passengersOnBus] <= departureTime) {
            passengersOnBus++;
        }
        
        index += passengersOnBus;
    }
    
    cout << buses << endl;
    
    return 0;
}