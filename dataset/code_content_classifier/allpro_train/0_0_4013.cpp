#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<double> prob(n);
    for (int i = 0; i < n; i++) {
        cin >> prob[i];
    }
    
    double expected_score = 0.0;
    
    for (int i = 0; i < n; i++) {
        double p = prob[i];
        double score = p*p + (1-p) * p + (1-p)*(1-p);
        expected_score += score;
    }
    
    cout << fixed;
    cout.precision(15);
    cout << expected_score * n << endl;

    return 0;
}