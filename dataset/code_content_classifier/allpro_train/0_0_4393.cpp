#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    map<int, int> freq;
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int diff = j - i;
            int sum = A[i] + A[j];
            int target = abs(diff - sum);
            count += freq[target];
            freq[diff] += 1;
        }
    }

    cout << count << endl;

    return 0;
}