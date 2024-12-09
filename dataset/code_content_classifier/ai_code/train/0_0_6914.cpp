#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    while (true) {
        int a, m, b, n;
        cin >> a >> m >> b >> n;
        if (a == 0 && m == 0 && b == 0 && n == 0) {
            break;
        }
        
        vector<int> coefficients;
        coefficients.push_back(1); // ad
        coefficients.push_back(0); // ad-1
        
        // Calculate the minimal polynomial coefficients
        for (int i = 2; i <= m * n; ++i) {
            int coef = 0;
            for (int j = 0; j < i; ++j) {
                coef += coefficients[j] * (j < a ? pow(m + n, i - j - 1) : pow(m - n, i - j - 1));
            }
            coefficients.push_back(coef);
        }
        
        // Output the coefficients of the minimal polynomial
        for (int i = coefficients.size() - 1; i >= 0; --i) {
            cout << coefficients[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}