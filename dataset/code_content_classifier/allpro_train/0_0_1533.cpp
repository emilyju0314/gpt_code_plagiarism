#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long p, k;
    cin >> p >> k;

    vector<int> coefficients;
    
    while (p != 0) {
        int remainder = p % k;
        if (remainder < 0) {
            remainder += k;
        }
        
        coefficients.push_back(remainder);
        p = (p - remainder) / (-k);
    }
    
    cout << coefficients.size() << endl;
    for (int i = 0; i < coefficients.size(); i++) {
        cout << coefficients[i] << " ";
    }
    
    return 0;
}