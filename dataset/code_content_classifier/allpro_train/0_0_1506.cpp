#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    string signs = "";
    int sum = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (sum >= (arr[i]+1)/2) {
            signs += "-";
            sum -= arr[i];
        } else {
            signs += "+";
            sum += arr[i];
        }
    }
    
    cout << signs << endl;
    
    return 0;
}