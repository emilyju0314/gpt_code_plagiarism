#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> songs(n);
    vector<int> group_count(m+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> songs[i];
        group_count[songs[i]]++;
    }

    int min_songs = n / m;
    int extra = n % m;

    vector<int> changes(n);
    for (int i = 0; i < m+1; i++) {
        if (group_count[i] > min_songs) {
            for (int j = 0; j < n; j++) {
                if (group_count[i] > min_songs && songs[j] == i) {
                    for (int k = 1; k < m+1; k++) {
                        if (group_count[k] < min_songs) {
                            songs[j] = k;
                            group_count[i]--;
                            group_count[k]++;
                            changes[j] = k;
                            break;
                        }
                    }
                }
            }
        }
    }

    cout << min_songs + (extra > 0) << " " << count_if(changes.begin(), changes.end(), [](int x) { return x != 0; }) << endl;
    for (int i = 0; i < n; i++) {
        cout << songs[i] << " ";
    }
    cout << endl;

    return 0;
}