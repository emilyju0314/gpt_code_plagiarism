#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> emotes(n);
    for(int i = 0; i < n; i++) {
        cin >> emotes[i];
    }

    sort(emotes.rbegin(), emotes.rend());

    long long result = 0;
    int repeats = m / (k + 1);
    result += repeats * (k * emotes[0] + emotes[1]);
    result += (m - repeats * (k + 1)) * emotes[0];

    cout << result << endl;

    return 0;
}