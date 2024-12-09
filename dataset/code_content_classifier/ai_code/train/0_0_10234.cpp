#include <iostream>
#include <vector>

using namespace std;

long long findGoodNumber(long long n) {
    vector<long long> powersOf3;
    long long power = 1;
    while(power <= n) {
        powersOf3.push_back(power);
        power *= 3;
    }
    
    long long target = 0;
    for(int i = powersOf3.size()-1; i >= 0; i--) {
        if(target + powersOf3[i] <= n) {
            target += powersOf3[i];
        }
    }
    
    return target;
}

int main() {
    int q;
    cin >> q;

    while(q--) {
        long long n;
        cin >> n;
        cout << findGoodNumber(n) << endl;
    }

    return 0;
}