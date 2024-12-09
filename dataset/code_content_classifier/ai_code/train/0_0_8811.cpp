#include <iostream>

using namespace std;

int countOperations(int n, int arr[]) {
    int operations = 0;
    
    for(int i=0; i<n; i++) {
        while(arr[i] % 2 == 0) {
            arr[i] /= 2;
            operations++;
        }
    }
    
    return operations;
}

int main() {
    int n;
    cin >> n;
    
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    int result = countOperations(n, arr);
    
    cout << result << endl;
    
    return 0;
}