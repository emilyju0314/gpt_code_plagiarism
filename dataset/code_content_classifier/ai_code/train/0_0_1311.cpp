#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, k, A;
vector<pair<int, int>> senators;

// Recursive function to get the probability of winning with given candies distribution
double getProbability(int index, int candies, int sumLevels, int sumLoyalties) {
    if (index == n) {
        if (sumLevels > 0) {
            double killProbability = (double)A / (A + sumLevels);
            if (killProbability > 1.0) killProbability = 1.0;
            return 1.0 - killProbability;
        }
        return 1.0;
    }
    
    if (candies == 0) {
        double killProbability = (double)A / (A + sumLevels);
        if (killProbability > 1.0) killProbability = 1.0;
        return 1.0 - killProbability;
    }
    
    double prob1 = (double)sumLoyalties / 100 * getProbability(index + 1, candies - 1, sumLevels - senators[index].first, sumLoyalties);
    double prob2 = getProbability(index + 1, candies, sumLevels, sumLoyalties);
    
    return max(prob1, prob2);
}

int main() {
    cin >> n >> k >> A;
    
    senators.resize(n);
    
    for (int i = 0; i < n; i++) {
        int level, loyalty;
        cin >> level >> loyalty;
        senators[i] = make_pair(level, loyalty);
    }
    
    double maxProbability = getProbability(0, k, 0, 0);
    
    cout.precision(10);
    cout << fixed << maxProbability << endl;
    
    return 0;
}