#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    long long T;
    cin >> n >> T;

    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long total_candies = 0;
    long long remaining_money = T;
    for(int i = 0; i < n; i++) {
        long long price = a[i];
        total_candies += remaining_money / price;
        remaining_money %= price;
    }
    
    cout << total_candies << endl;

    return 0;
}