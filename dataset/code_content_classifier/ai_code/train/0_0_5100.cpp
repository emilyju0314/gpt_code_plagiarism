#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double divisorSum(double n) {
    double sum = 1;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            sum += i;
            if(i != n/i) {
                sum += n/i;
            }
        }
    }
    return sum;
}

int main() {
    double k;
    cout << fixed << setprecision(6);

    while(true) {
        cin >> k;
        if(k == 0) {
            break;
        }
        
        double maxRatio = 0;
        for(int i = 1; i <= k; i++) {
            double ratio = divisorSum(i) / i;
            maxRatio = max(maxRatio, ratio);
        }

        cout << maxRatio << endl;
    }

    return 0;
}