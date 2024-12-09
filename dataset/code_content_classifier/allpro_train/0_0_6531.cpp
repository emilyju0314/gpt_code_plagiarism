#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> beauty(n);
    for(int i = 0; i < n; i++) {
        cin >> beauty[i];
    }
    
    sort(beauty.begin(), beauty.end());
    
    long long maxDiff = beauty[n-1] - beauty[0];
    
    long long ways = 0;
    if(maxDiff == 0) {
        ways = (long long)n*(n-1)/2;
    } else {
        long long countLower = count(beauty.begin(), beauty.end(), beauty[0]);
        long long countUpper = count(beauty.begin(), beauty.end(), beauty[n-1]);
        ways = countLower*countUpper;
    }
    
    cout << maxDiff << " " << ways << endl;
    
    return 0;
}