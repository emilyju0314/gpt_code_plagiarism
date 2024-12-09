#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, p, k;
    cin >> n >> p >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> counts(p, 0);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int sum = (a[i] + a[j]) % p;
            int product = (a[i]*a[i] + a[j]*a[j]) % p;
            if((sum * product) % p == k) {
                counts[sum]++;
            }
        }
    }

    int answer = 0;
    for(int i = 0; i < p; i++) {
        answer += counts[i] * (counts[i] - 1) / 2;
    }

    cout << answer << endl;

    return 0;
}