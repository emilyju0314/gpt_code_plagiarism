#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<int> difficulties(n);
    for(int i = 0; i < n; i++) {
        cin >> difficulties[i];
    }

    int result = 0;
    int prefix_sum = 0;
    int power_of_2 = 1;

    for(int i = 0; i < n; i++) {
        prefix_sum = (prefix_sum + difficulties[i]) % MOD;
        result = (result + (prefix_sum * power_of_2) % MOD) % MOD;
        power_of_2 = (power_of_2 * 2) % MOD;
    }

    cout << result << endl;

    return 0;
}