#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long sum = 0;
    unordered_map<long long, int> remainderCount;
    remainderCount[0] = 1;

    long long result = 0;
    for (int i = 0; i < N; i++) {
        sum = (sum + A[i]) % M;
        result += remainderCount[sum];
        remainderCount[sum]++;
    }

    cout << result << endl;

    return 0;
}