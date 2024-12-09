#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int maxLength = 1;
    int start = 0;
    int end = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] <= a[i-1]) {
            start = i;
        }
        end = i;
        maxLength = max(maxLength, end - start + 1);
    }
    
    cout << maxLength << endl;
    
    return 0;
}