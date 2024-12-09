#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> permutation(n);
    for(int i=0; i<n; i++) {
        cin >> permutation[i];
    }

    long long ans = 0;
    for(int i=0; i<n; i++) {
        vector<int> left_count(n+1, 0);
        vector<int> right_count(n+1, 0);
        int left_max = 0, right_min = n+1;
        for(int j=i; j<n; j++) {
            right_min = min(right_min, permutation[j]);
            right_count[right_min]++;
            left_max = max(left_max, permutation[j]);
            left_count[left_max]++;

            ans += (long long)left_count[right_min-1] + right_count[left_max+1];
        }
    }

    cout << ans << endl;

    return 0;
}