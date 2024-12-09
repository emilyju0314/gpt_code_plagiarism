#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> colors(n+1, 0);
    int curr_color = 1;

    for (int i = 2; i <= n+1; i++) {
        if (colors[i] == 0) {
            colors[i] = curr_color;
            for (int j = i*2; j <= n+1; j+=i) {
                if (is_prime(j/i)) {
                    colors[j] = curr_color;
                }
            }
            curr_color++;
        }
    }

    cout << curr_color - 1 << endl;
    for (int i = 2; i <= n+1; i++) {
        cout << colors[i] << " ";
    }

    return 0;
}