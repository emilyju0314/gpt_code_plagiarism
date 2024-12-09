#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    // three operations to make all elements zero
    cout << "1 1" << endl;
    cout << -a[0] << endl;
    
    cout << "2 2" << endl;
    cout << -a[1] << endl;
    
    cout << "3 " << n << endl;
    long long sum = 0;
    for(int i=2; i<n; i++) {
        cout << -a[i] * (n-1) << " ";
        sum += a[i];
    }
    cout << -sum * 2 << endl;
    
    return 0;
}