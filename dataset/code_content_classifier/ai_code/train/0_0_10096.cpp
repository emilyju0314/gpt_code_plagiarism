#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    int maxLength = 1;
    int currentLength = 1;
    
    for(int i=1; i<n; i++) {
        if(arr[i] > arr[i-1]) {
            currentLength++;
            maxLength = max(maxLength, currentLength);
        } else {
            currentLength = 1;
        }
    }
    
    cout << maxLength << endl;
    
    return 0;
}