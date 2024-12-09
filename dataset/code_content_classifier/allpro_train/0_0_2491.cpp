#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<string> strings(N);
    unordered_map<string, int> counts;
    
    for (int i = 0; i < N; i++) {
        cin >> strings[i];
        string s = strings[i];
        sort(s.begin(), s.end());
        counts[s]++;
    }
    
    long long ans = 0;
    
    for (auto p : counts) {
        int n = p.second;
        ans += (long long)n * (n - 1) / 2;
    }
    
    cout << ans << endl;
    
    return 0;
}