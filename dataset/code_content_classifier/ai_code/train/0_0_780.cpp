#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> pairs(n);
    
    int maxGCD = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> pairs[i].first >> pairs[i].second;
        maxGCD = gcd(maxGCD, gcd(pairs[i].first, pairs[i].second));
    }
    
    if(maxGCD == 1) {
        cout << -1 << endl;
    } else {
        cout << maxGCD << endl;
    }

    return 0;
}