#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> sizes(n);
    for(int i = 0; i < n; i++) {
        cin >> sizes[i];
    }
    
    int p;
    cin >> p;
    
    vector<int> factorial(n + 1, 1);
    for(int i = 2; i <= n; i++) {
        factorial[i] = i * factorial[i - 1];
    }
    
    double total = 0;
    vector<int> permutation(n);
    for(int i = 0; i < n; i++) {
        permutation[i] = i;
    }
    
    do {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += sizes[permutation[i]];
            if(sum > p) {
                break;
            }
            total++;
        }
    } while(next_permutation(permutation.begin(), permutation.end()));
    
    cout.precision(10);
    cout << total / factorial[n] << endl;
    
    return 0;
}