#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a.push_back(a[i]);
    }
    
    vector<int> pi(2 * n, 0);
    int j = 0;
    for(int i = 1; i < 2 * n; i++) {
        while(j > 0 && a[i] != a[j]) {
            j = pi[j - 1];
        }
        if(a[i] == a[j]) {
            j++;
        }
        pi[i] = j;
    }
    
    long long result = 0;
    j = 0;
    for(int i = n; i < 2 * n; i++) {
        while(j > 0 && a[i] != a[j]) {
            j = pi[j - 1];
        }
        if(a[i] == a[j]) {
            j++;
        }
        result += j;
    }
    
    cout << result - n; // Remove the overlapping cases
    
    return 0;
}