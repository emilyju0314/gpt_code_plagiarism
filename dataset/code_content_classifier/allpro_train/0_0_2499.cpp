#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N, L;
    cin >> N >> L;
    
    long long total_volume = 0;
    double total_temperature = 0.0;
    
    for(int i = 0; i < N; i++) {
        int t, v;
        cin >> t >> v;
        
        double max_temperature = 0.0;
        
        if(total_volume + v <= L) {
            total_volume += v;
            total_temperature += v * t;
            max_temperature = total_temperature / total_volume;
        } else {
            double overflow = total_volume + v - L;
            double remaining_volume = v - overflow;
            total_volume = L;
            
            double new_temperature = total_temperature + remaining_volume * t;
            max_temperature = new_temperature / L;
            total_temperature = overflow * t;
        }
        
        cout << fixed << setprecision(7) << max_temperature << endl;
    }
    
    return 0;
}