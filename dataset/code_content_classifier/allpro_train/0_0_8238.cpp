#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, d, e;
    cin >> n >> d >> e;
    
    int min_rubles = n;
    
    for(int i=0; i<=n; i+=5*e) {
        int remaining = n - i;
        min_rubles = min(min_rubles, remaining % d);
    }
    
    cout << min_rubles << endl;
    
    return 0;
}