#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coefficients(n+1);
    for(int i=0; i<=n; i++) {
        cin >> coefficients[i];
    }
    
    int ways = 0;
    int original = 0;
    for(int i=0; i<=n; i++) {
        original += coefficients[i] * pow(2, i);
    }

    for(int i=0; i<=n; i++) {
        int current = original - coefficients[i] * pow(2, i);

        if(abs(current) <= k * pow(2, i)) {
            ways++;
        }
    }

    cout << ways << endl;

    return 0;
}