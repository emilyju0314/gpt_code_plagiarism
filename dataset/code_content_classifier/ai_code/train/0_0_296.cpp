#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> genres(n);
    for(int i = 0; i < n; i++) {
        cin >> genres[i];
    }

    vector<int> genreCount(m+1, 0);
    for(int i = 0; i < n; i++) {
        genreCount[genres[i]]++;
    }

    long long totalWays = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = i + 1; j <= m; j++) {
            totalWays += (long long) genreCount[i] * genreCount[j];
        }
    }

    cout << totalWays << endl;

    return 0;
}