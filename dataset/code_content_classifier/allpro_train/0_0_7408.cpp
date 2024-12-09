#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n;
    cin >> n;
    
    long long games = 0;
    while(n > 1) {
        long long x = (long long)sqrt(n);
        games++;
        n -= x;
    }
    
    cout << games << endl;
    
    return 0;
}