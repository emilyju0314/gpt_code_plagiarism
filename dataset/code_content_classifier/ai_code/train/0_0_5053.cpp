#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

double expected_counter(string name, int n, int h) {
    if(name == "Alice") {
        double expected_value = 0.0;
        for(int i = 1; i <= n; i++) {
            expected_value += 1.0 / i;
        }
        return expected_value;
    } else {
        vector<double> dp(n+1, 0.0); 
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= h; j++) {
                dp[1] += 1.0 / (2 * i);
                if(j > 0) {
                    dp[1] += 1.0 / (2 * i);
                }
            }
        }

        for(int i = 2; i <= n; i++) {
            for(int j = 0; j <= h; j++) {
                dp[i] += dp[i-1];
                if(j > 0) {
                    dp[i] += dp[i-1];
                }
            }
        }

        return dp[n];
    }
}

int main() {
    string name;
    int n, h;

    cin >> name >> n >> h;

    double result = expected_counter(name, n, h);

    cout << fixed << setprecision(9) << result << endl;

    return 0;
}