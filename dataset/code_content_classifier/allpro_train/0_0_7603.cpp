#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int K, T;
    cin >> K >> T;
    
    int a[100];
    int max_a = 0;
    for (int i = 0; i < T; i++) {
        cin >> a[i];
        max_a = max(max_a, a[i]);
    }
    
    int total_cakes = 0;
    for (int i = 0; i < T; i++) {
        total_cakes += a[i];
    }

    int max_same_cake_days = max(0, 2 * max_a - total_cakes - 1);
    cout << max_same_cake_days << endl;

    return 0;
}