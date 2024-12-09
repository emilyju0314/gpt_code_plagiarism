#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    long long sum = 0;
    long long min_dev = n * n;
    int best_shift = 0;
    
    for(int i = 0; i < n; i++) {
        sum += p[i];
    }
    
    for(int i = 0; i < n; i++) {
        long long dev = sum - (long long)n * p[i];
        if(dev < min_dev) {
            min_dev = dev;
            best_shift = i;
        }
    }
    
    cout << min_dev << " " << best_shift << endl;
    
    return 0;
}