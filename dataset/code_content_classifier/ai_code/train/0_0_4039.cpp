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

    int cash = 0;
    int shares = 0;

    for(int i = 0; i < N - 1; i++) {
        if(prices[i] < prices[i + 1] && shares == 0) {
            // Buy one share
            cash -= prices[i];
            shares++;
        }
        else if(prices[i] > prices[i + 1] && shares > 0) {
            // Sell one share
            cash += prices[i];
            shares--;
        }
    }

    // If we still hold shares at the end, sell them to get cash
    if(shares > 0) {
        cash += prices[N - 1];
    }

    cout << cash << endl;

    return 0;
}