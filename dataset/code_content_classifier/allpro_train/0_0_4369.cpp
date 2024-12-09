#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    long long n;
    string t;
    cin >> n >> t;

    vector<int> cnt(4, 0);
    for(char c : t) {
        if(c == 'A') cnt[0]++;
        else if(c == 'B') cnt[1]++;
        else if(c == 'C') cnt[2]++;
        else cnt[3]++;
    }

    long long min_occurrences = n;
    for(int i = 0; i < 4; i++) {
        min_occurrences = min(min_occurrences, (long long) cnt[i]);
    }

    cout << min_occurrences * n << endl;

    return 0;
}