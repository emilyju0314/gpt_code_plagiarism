#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        long long s, a, b, c;
        cin >> s >> a >> b >> c;
        
        long long numBars = s / c;
        long long numFreeBars = (numBars / a) * b;
        cout << numBars + numFreeBars << endl;
    }
    
    return 0;
}