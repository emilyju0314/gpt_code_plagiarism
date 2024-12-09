#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> songs(n);
    for(int i = 0; i < n; i++) {
        int type;
        cin >> type;
        if(type == 1) {
            string c;
            cin >> c;
            songs[i] = c;
        } else {
            int j;
            string prev_song, c;
            cin >> j >> prev_song >> c;
            songs[i] = songs[j-1] + c;
        }
    }

    int m;
    cin >> m;

    for(int i = 0; i < m; i++) {
        int current_song;
        string t;
        cin >> current_song >> t;

        string song = songs[current_song-1];
        int count = 0;
        for(size_t j = 0; j <= song.size() - t.size(); j++) {
            if(song.substr(j, t.size()) == t) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}