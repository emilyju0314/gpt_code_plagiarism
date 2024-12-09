#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            if(arr[i] != 1) {
                cout << "1 ";
            } else {
                cout << "1 ";
            }
        } else {
            if(arr[i] != arr[i-1]) {
                cout << arr[i-1] << " ";
            } else {
                if(arr[i] != 1) {
                    cout << "1 ";
                } else {
                    cout << "2 ";
                }
            }
        }
    }
    
    return 0;
}