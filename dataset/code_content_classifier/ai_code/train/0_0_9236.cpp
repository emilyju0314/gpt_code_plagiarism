#include <iostream>
#include <vector>

using namespace std;

// Function to perform polynomial long division
pair<vector<int>, vector<int>> polynomialLongDivision(vector<int> dividend, vector<int> divisor) {
    vector<int> quotient;
    while(dividend.size() >= divisor.size()) {
        int coeff = dividend.back() / divisor.back();
        quotient.push_back(coeff);
        
        for(int i = 0; i < divisor.size(); i++) {
            dividend[dividend.size() - i - 1] -= coeff * divisor[divisor.size() - i - 1];
        }
        
        // Remove leading zeros
        while(!dividend.empty() && dividend.back() == 0) {
            dividend.pop_back();
        }
    }
    
    return make_pair(quotient, dividend);
}

int main() {
    int n;
    cin >> n;
    
    if (n == 1) {
        cout << "1\n";
        cout << "0 1\n";
        cout << "0\n";
        cout << "1\n";
        return 0;
    }
    
    // Generate polynomials with specified degrees and coefficients
    vector<int> a(n + 1, 0);
    vector<int> b(n, 0);
    a.back() = 1;
    
    cout << n << endl;
    for(int coeff : a) {
        cout << coeff << " ";
    }
    cout << endl;
    
    cout << n - 1 << endl;
    for(int coeff : b) {
        cout << coeff << " ";
    }
    cout << endl;
    
    return 0;
}