#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    int n;
    cin >> n;

    vector<pair<long long, long long>> cards(n);
    for (int i = 0; i < n; i++) {
        cin >> cards[i].first >> cards[i].second;
    }

    long long nim_sum = 0;
    for (int i = 0; i < n; i++) {
        nim_sum ^= (cards[i].first ^ cards[i].second);
    }

    if (nim_sum == 0) {
        cout << "0/1" << endl;
    } else {
        long long total_winning_strategies = 0;
        for (int i = 0; i < n; i++) {
            long long partial_nim_sum = nim_sum ^ (cards[i].first ^ cards[i].second);
            if ((partial_nim_sum & partial_nim_sum - 1) == 0) {
                total_winning_strategies++;
            }
        }

        long long total_strategies = 0;
        for (int i = 0; i < n; i++) {
            long long total_stones = cards[i].first + cards[i].second;
            if (total_stones != 0) {
                total_strategies += total_stones;
            }
        }

        long long common_divisor = gcd(total_winning_strategies, total_strategies);

        cout << total_winning_strategies / common_divisor << "/" << total_strategies / common_divisor << endl;
    }

    return 0;
}