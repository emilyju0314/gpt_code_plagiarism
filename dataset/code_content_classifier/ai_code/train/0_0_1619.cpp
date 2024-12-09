#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long p, k;
    cin >> p >> k;
    
    if (k == 2) {
        cout << "1" << endl;
        cout << p << endl;
    }
    else {
        vector<int> coeffs;
        
        while (p != 0) {
            int rem = p % k;
            if (rem < 0) rem += k;  // Make sure remainder is non-negative
            coeffs.push_back(rem);
            p = (p - rem) / -k;
        }
        
        cout << coeffs.size() << endl;
        for (int i = 0; i < coeffs.size(); i++) {
            cout << coeffs[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}