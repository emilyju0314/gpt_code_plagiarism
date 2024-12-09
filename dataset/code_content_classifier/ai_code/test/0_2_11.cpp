#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n+1);
    for (int i = 1; i <=n; i++) {
        cin >> a[i];
    }

    int count_ai_equals_i = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == i) {
            count_ai_equals_i++;
        }
    }

    int max_fa_prime = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != i && a[a[i]] == i) {
            int candidate_count = count_ai_equals_i - 2 + 1;
            max_fa_prime = max(max_fa_prime, candidate_count);
        }
    }

    cout << max(count_ai_equals_i, max_fa_prime) << endl;

    return 0;
}