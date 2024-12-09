#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    map<int, int> diffCounts; // Map to store the count of differences in A
    vector<int> diffs(N+1, 0); // Vector to store the cumulative differences in A

    // Calculate the cumulative differences in A
    for(int i = 0; i < N; i++) {
        if(S[i] == '+') {
            diffs[i+1] = diffs[i] + 1;
        } else if(S[i] == '-') {
            diffs[i+1] = diffs[i] - 1;
        } else if(S[i] == '>') {
            diffs[i+1] = diffs[i];
        } else if(S[i] == '<') {
            diffs[i+1] = diffs[i];
        }
    }

    // Count the number of possible pairs (i, j)
    long long ans = 0;
    for(int j = 0; j <= N; j++) {
        ans += diffCounts[diffs[j]];
        diffCounts[diffs[j]]++;
    }

    cout << ans << endl;

    return 0;
}