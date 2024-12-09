#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> result(n-1, 1);
    int current = 2;
    
    for (int i = 3; i <= n; i++) {
        if (result[i-2] == 1) {
            result[i-2] = current;
            for (int j = i*2; j <= n; j += i) {
                result[j-2] = current;
            }
            current++;
        }
    }

    for (int i = 0; i < n-1; i++) {
        cout << result[i] << " ";
    }

    return 0;
}