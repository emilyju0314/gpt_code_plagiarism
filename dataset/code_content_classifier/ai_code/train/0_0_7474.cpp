#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Song {
    int length, probability;
};

bool compare(Song a, Song b) {
    return a.probability > b.probability;
}

int main() {
    int n;
    cin >> n;

    vector<Song> songs(n);
    for(int i = 0; i < n; i++) {
        cin >> songs[i].length >> songs[i].probability;
    }

    sort(songs.begin(), songs.end(), compare);

    long long total_length = 0;
    long long total_probability = 0;
    for(int i = 0; i < n; i++) {
        total_length += (total_probability + songs[i].probability) * songs[i].length;
        total_probability += songs[i].probability;
    }

    double expected_time = (double) total_length / 100.0;

    cout << fixed;
    cout.precision(9);
    cout << expected_time << endl;

    return 0;
}