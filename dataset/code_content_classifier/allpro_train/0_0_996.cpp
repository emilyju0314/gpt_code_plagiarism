#include <iostream>
#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> freq(4, 0);
    for(int i = 0; i < n; i++) {
        if(s[i] == 'A') freq[0]++;
        else if(s[i] == 'C') freq[1]++;
        else if(s[i] == 'G') freq[2]++;
        else if(s[i] == 'T') freq[3]++;
    }

    int max_freq = *max_element(freq.begin(), freq.end());
    int max_count = 0;
    for(int i = 0; i < 4; i++) {
        if(freq[i] == max_freq) max_count++;
    }

    long long ans = 1;
    for(int i = 0; i < n; i++) {
        ans = (ans * max_count) % MOD;
    }

    cout << ans << endl;

    return 0;
}