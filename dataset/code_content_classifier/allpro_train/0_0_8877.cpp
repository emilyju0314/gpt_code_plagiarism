#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int min_days_off, max_days_off;
    
    if (n % 7 == 0) {
        min_days_off = max_days_off = n / 7 * 2;
    } else {
        int weeks = n / 7;
        int remainder = n % 7;
        
        min_days_off = weeks * 2;
        
        if (remainder == 6) {
            min_days_off++;
        }
        
        max_days_off = weeks * 2 + min(2, remainder);
    }
    
    cout << min_days_off << " " << max_days_off << endl;

    return 0;
}