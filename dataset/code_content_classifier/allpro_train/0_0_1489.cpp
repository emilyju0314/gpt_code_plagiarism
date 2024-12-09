#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_valid(string s) {
    int balance = 0;
    for (char c : s) {
        if (c == '(') balance++;
        else balance--;
        if (balance < 0) return false;
    }
    return balance == 0;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> prefix_sum(n + 1);
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + (s[i] == '(' ? 1 : -1);
    }

    int max_balance = 0;
    int swap_idx1 = -1, swap_idx2 = -1;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(s[i], s[j]);
            if (is_valid(s)) {
                int balance = prefix_sum[j + 1] - prefix_sum[i];
                if (balance > max_balance) {
                    max_balance = balance;
                    swap_idx1 = i;
                    swap_idx2 = j;
                }
            }
            swap(s[i], s[j]);
        }
    }

    cout << max_balance << endl;
    cout << swap_idx1 + 1 << " " << swap_idx2 + 1 << endl;

    return 0;
}