#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> prices(n);
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    
    sort(prices.begin(), prices.end());
    
    vector<int> result;
    
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            result.push_back(prices[(n-1)/2 - i/2]);
        } else {
            result.push_back(prices[n/2 + i/2]);
        }
    }
    
    int count = 0;
    for(int i = 1; i < n-1; i++) {
        if(result[i] < result[i-1] && result[i] < result[i+1]) {
            count++;
        }
    }
    
    cout << count << endl;
    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}