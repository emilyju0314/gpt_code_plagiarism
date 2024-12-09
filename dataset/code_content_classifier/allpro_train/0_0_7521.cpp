#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, w;
    
    while (true) {
        cin >> n >> w;
        
        if (n == 0 && w == 0) {
            break;
        }
        
        vector<int> values(n);
        
        for (int i = 0; i < n; i++) {
            cin >> values[i];
        }
        
        sort(values.begin(), values.end());
        
        int intervals = values.back() / w;
        vector<int> frequencies(intervals, 0);
        
        for (int value : values) {
            frequencies[value / w]++;
        }
        
        int max_frequency = *max_element(frequencies.begin(), frequencies.end());
        double ink_consumed = 0.01;
        
        for (int freq : frequencies) {
            double darkness = (double)freq / max_frequency;
            ink_consumed += (1 - darkness) * w / intervals;
        }
        
        cout << fixed;
        cout.precision(10);
        cout << ink_consumed << endl;
    }
    
    return 0;
}