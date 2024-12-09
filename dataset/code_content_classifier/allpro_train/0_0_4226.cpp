#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<long long> x(N), s(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> s[i];
    }
    
    long long max_profit = 0;
    long long current_profit = 0;
    
    for (int i = 0; i < N; i++) {
        current_profit += s[i];
        max_profit = max(max_profit, current_profit - x[i]);
    }

    cout << max_profit << endl;
    
    return 0;
}