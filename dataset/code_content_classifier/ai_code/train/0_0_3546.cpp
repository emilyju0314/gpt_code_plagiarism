#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<double> P(N);
    for(int i = 0; i < N; i++) {
        cin >> P[i];
    }
    
    double profit = 0.0;
    
    for(int i = 0; i < N; i++) {
        // Calculate the expected value of the amount of money consumed until the S rare card i is obtained
        double expected_value = 1.0 / P[i];
        double appearance_rate = 0.01; // Start with 0.01%
        
        // Increase the appearance rate until the sum of appearance rates is 3%
        while(appearance_rate < 3.0) {
            double current_profit = P[i] * expected_value;
            for(int j = 0; j < N; j++) {
                if(j != i) {
                    current_profit += P[j] * (1.0 / P[j]) * appearance_rate / 3.0;
                }
            }
            
            // Update the profit if the current profit is lower
            profit = max(profit, current_profit);
            
            appearance_rate += 0.01; // Increase appearance rate by 0.01%
        }
    }
    
    cout << fixed << setprecision(6) << profit << endl;
    
    return 0;
}