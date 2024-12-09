#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector<int> bag1(n1), bag2(n2), bag3(n3);
    for(int i=0; i<n1; i++) {
        cin >> bag1[i];
    }
    for(int i=0; i<n2; i++) {
        cin >> bag2[i];
    }
    for(int i=0; i<n3; i++) {
        cin >> bag3[i];
    }

    sort(bag1.rbegin(), bag1.rend());
    sort(bag2.rbegin(), bag2.rend());
    sort(bag3.rbegin(), bag3.rend());

    vector<long long> prefix_sum1(n1+1), prefix_sum2(n2+1), prefix_sum3(n3+1);

    for(int i=1; i<=n1; i++) {
        prefix_sum1[i] = prefix_sum1[i-1] + bag1[i-1];
    }
    for(int i=1; i<=n2; i++) {
        prefix_sum2[i] = prefix_sum2[i-1] + bag2[i-1];
    }
    for(int i=1; i<=n3; i++) {
        prefix_sum3[i] = prefix_sum3[i-1] + bag3[i-1];
    }

    long long result = 0;

    for(int i=0; i<=min(n1, n2); i++) {
        long long sum = prefix_sum1[i] + prefix_sum2[i];
        sum += prefix_sum3[min(n3, n1+n2-i)];
        result = max(result, sum);
    }

    cout << result << endl;

    return 0;
}