#include <iostream>
#include <vector>

using namespace std;

bool isCoprime(int x, int y) {
    while (y != 0) {
        int temp = x % y;
        x = y;
        y = temp;
    }
    return x == 1;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j && !isCoprime(arr[i], arr[j])) {
                cout << "0" << endl;
                return 0;
            }
        }
    }
    
    cout << "1" << endl;
    
    return 0;
}