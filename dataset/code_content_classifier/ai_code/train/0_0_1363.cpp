#include <iostream>

using namespace std;

int main() {
    long long k, d, t;
    cin >> k >> d >> t;
    
    long long period = 2*k + (d - (2*k%d))%d;
    
    long double time;
    if(t <= period) {
        time = t;
    } else {
        long long full_cycles = t / period;
        long long remaining_time = t % period;
        time = full_cycles * period;
        
        if(remaining_time <= 2*k) {
            time += remaining_time/2.0;
        } else {
            time += k;
            remaining_time -= 2*k;
            time += remaining_time;
        }
    }
    
    cout << fixed;
    cout.precision(9);
    cout << time << endl;
    
    return 0;
}