#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> dislikes(K);
    for(int i = 0; i < K; i++) {
        cin >> dislikes[i];
    }

    // Find the minimum amount of money that Iroha will hand to the cashier
    int ans = N;
    while(true) {
        bool valid = true;
        int num = ans;
        while(num > 0) {
            int digit = num % 10;
            for(int d : dislikes) {
                if(digit == d) {
                    valid = false;
                    break;
                }
            }
            num /= 10;
        }
        if(valid) {
            break;
        }
        ans++;
    }

    cout << ans << endl;

    return 0;
}