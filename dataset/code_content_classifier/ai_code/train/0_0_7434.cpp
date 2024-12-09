#include <iostream>
#include <vector>

using namespace std;

int p, q, a, n;

int countPartitions(int numerator, int denominator, int maxDenominator, int maxFractions) {
    if (numerator == 0) {
        return 1;
    }
    if (maxFractions == 0 || maxDenominator == 0) {
        return 0;
    }
    
    int count = 0;
    for (int i = min(numerator, maxDenominator); i >= 1; i--) {
        count += countPartitions(numerator * i - denominator, denominator * i, i, maxFractions - 1);
    }
    
    return count;
}

int main() {
    while (cin >> p >> q >> a >> n) {
        if (p == 0 && q == 0 && a == 0 && n == 0) {
            break;
        }
        
        int result = countPartitions(p, q, a, n);
        cout << result << endl;
    }
    
    return 0;
}