#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<double> probabilities(n);
    for (int i = 0; i < n; i++) {
        cin >> probabilities[i];
    }
    
    sort(probabilities.rbegin(), probabilities.rend());
    
    double maxProbability = 0;
    
    for (int i = 0; i <= n; i++) {
        double currentProbability = 1;
        for (int j = 0; j < i; j++) {
            currentProbability *= probabilities[j];
        }
        if (i < n) {
            for (int j = i; j < n; j++) {
                currentProbability *= (1 - probabilities[j]);
            }
        }
        maxProbability = max(maxProbability, currentProbability);
    }
    
    cout << fixed;
    cout.precision(12);
    cout << maxProbability << endl;
    
    return 0;
}