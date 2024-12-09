#include <iostream>
using namespace std;

int main() {
    long long n, m, a;
    cin >> n >> m >> a;

    long long flagstonesNeeded = ((n + a - 1) / a) * ((m + a - 1) / a);
    
    cout << flagstonesNeeded << endl;

    return 0;
}