#include <iostream>
#include <vector>

using namespace std;

bool isCoprime(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a == 1;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> result;
    
    for (int i = 0; i < n; i++) {
        result.push_back(arr[i]);
        
        if (i < n - 1 && !isCoprime(arr[i], arr[i+1])) {
            int gcd = 1;
            while (!isCoprime(arr[i], gcd) || !isCoprime(gcd, arr[i+1])) {
                gcd++;
            }
            result.push_back(gcd);
        }
    }
    
    cout << result.size() - n << endl;
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}