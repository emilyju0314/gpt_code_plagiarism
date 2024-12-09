#include <iostream>
#include <cmath>

using namespace std;

pair<int, int> getCoordinates(long long n) {
    long long k = sqrt(n);
    if(k*k == n) {
        if(k % 2 == 1) return {-(k/2), -(k/2)};
        else return {k/2-1, k/2};
    }
    
    k++;
    n -= (k-1)*(k-1);
    long long side = n / (k-1);
    long long remain = n % (k-1);
    
    if(side == 0) {
        return {k/2-remain, -k/2};
    } else if(side == 1) {
        return {k/2-remain, -k/2+remain};
    } else if(side == 2) {
        return {-(k/2), remain};
    } else if(side == 3) {
        return {-(k/2)+remain, k/2-remain};
    } else if(side == 4) {
        return {k/2, -remain};
    } else {
        return {k/2, k/2-remain};
    }
}

int main() {
    long long n;
    cin >> n;
    
    pair<int, int> coords = getCoordinates(n);
    cout << coords.first << " " << coords.second << endl;
    
    return 0;
}