#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;

    vector<int> bearsWall(n);
    for (int i = 0; i < n; i++) {
        cin >> bearsWall[i];
    }

    vector<int> elephantWall(w);
    for (int i = 0; i < w; i++) {
        cin >> elephantWall[i];
    }

    int count = 0;
    vector<int> prefixMatches(w);

    // Calculate the prefix array for elephant wall
    for (int i = 1, j = 0; i < w; i++) {
        while (j > 0 && elephantWall[i] != elephantWall[j]) {
            j = prefixMatches[j - 1];
        }
        if (elephantWall[i] == elephantWall[j]) {
            j++;
        }
        prefixMatches[i] = j;
    }

    // Perform KMP algorithm to find matches in bears wall
    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && bearsWall[i] != elephantWall[j]) {
            j = prefixMatches[j - 1];
        }
        if (bearsWall[i] == elephantWall[j]) {
            j++;
            if (j == w) {
                count++;
                j = prefixMatches[j - 1];
            }
        }
    }

    cout << count << endl;

    return 0;
}