#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> prices(N);
    for(int i = 0; i < N; i++) {
        cin >> prices[i];
    }

    long long profit = 0;
    int shares = 0;

    for(int i = 0; i < N - 1; i++) {
        if(prices[i] < prices[i + 1] && shares == 0) {
            shares = 1;
            profit -= prices[i];
        } else if(prices[i] > prices[i + 1] && shares == 1) {
            shares = 0;
            profit += prices[i];
        }
    }

    if(shares == 1) {
        profit += prices[N - 1];
    }

    cout << profit << endl;

    return 0;
}