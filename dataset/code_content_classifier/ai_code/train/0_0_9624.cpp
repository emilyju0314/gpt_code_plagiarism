#include <iostream>

using namespace std;

int main() {
    int n, v;
    cin >> n >> v;

    int cost = 0;
    for(int i = 2; i <= n; i++) {
        if(i < n) {
            // Refill tank in each city
            int fuel_needed = min(v, n - i);
            cost += fuel_needed * i;
        } else {
            // Final city, refill tank completely
            cost += v;
        }
    }

    cout << cost << endl;

    return 0;
}