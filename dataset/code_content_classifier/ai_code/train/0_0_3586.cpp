#include <iostream>
#include <vector>

using namespace std;

double g(vector<double>& a, double x) {
    double ans = x;
    for (double ai : a) {
        ans = max(ans * ai, ans + ai);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    
    vector<double> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    double sum = 0;
    for (int i = 0; i < n; i++) {
        vector<double> prefix(b.begin(), b.begin() + i + 1);
        vector<double> suffix(b.begin() + i, b.end());
        
        sum += g(prefix, 0) + g(suffix, 0);
    }
    
    double result = sum / (n * n);
    cout << result << endl;
    
    return 0;
}