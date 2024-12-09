#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the maximum sum of water heights in compartments
double maxWaterHeightSum(int N, int M, vector<int>& a) {
    double maxSum = 0.0;
    
    // Iterate through all possible combinations of removing dividers
    for (int mask = 0; mask < (1 << (N-1)); mask++) {
        int cnt = 0;
        double sum = 0.0;
        
        // Calculate the sum of water heights in each compartment
        for (int i = 0; i < N; i++) {
            if (i == 0 || ((mask & (1 << cnt)) == 0)) {
                sum += a[i];
            } else {
                cnt++;
                sum += a[i];
            }
        }
        
        if (cnt <= M) {
            maxSum = max(maxSum, sum);
        }
    }
    
    return maxSum;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    double result = maxWaterHeightSum(N, M, a);
    cout << fixed << result << endl;
    
    return 0;
}