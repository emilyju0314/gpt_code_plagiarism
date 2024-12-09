#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> array(n);
    
    for(int i = 0; i < n; i++) {
        cin >> array[i];
    }
    
    sort(array.begin(), array.end());
    
    int result = 0;
    
    for(int num : array) {
        if(num < x) {
            result += x - num;
        }
    }
    
    if(array[n/2] != x) {
        result++;
    }
    
    cout << result << endl;
    
    return 0;
}