#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    
    return true;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> x(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }
    
    int max_x = *max_element(x.begin(), x.end());
    int ans = max_x;
    while (true) {
        bool flag = true;
        for (int i = 2; i <= max_x; i++) {
            if (isPrime(i)) {
                int cnt = 0;
                for (int j = 0; j < N; j++) {
                    if (x[j] % i == 0) cnt++;
                }
                if (cnt > N/2) {
                    flag = false;
                    for (int j = 0; j < N; j++) x[j] = (x[j] % i == 0 ? x[j] / i : x[j]);
                }
            }
        }
        
        if (flag) break;
        ans++;
    }
    
    cout << ans << endl;
    
    return 0;
}