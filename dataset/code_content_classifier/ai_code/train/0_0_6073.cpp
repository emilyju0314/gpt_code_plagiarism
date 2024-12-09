#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> permutation(n);
    for (int i = 0; i < n; i++) {
        cin >> permutation[i];
    }
    
    vector<int> f(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += i - permutation[i] + 1;
        f[i] = sum;
    }
    
    for (int i = 0; i < n; i++) {
        cout << f[i] << " ";
    }
    
    return 0;
}