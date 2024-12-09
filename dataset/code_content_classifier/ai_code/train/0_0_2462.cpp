#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> songs;
    for (int i = 0; i < n; i++) {
        int c, t;
        std::cin >> c >> t;
        songs.push_back({c, t});
    }

    std::vector<int> moments(m);
    for (int i = 0; i < m; i++) {
        std::cin >> moments[i];
    }

    std::vector<int> song_at_moment;
    int total_duration = 0;
    for (int i = 0; i < n; i++) {
        total_duration += songs[i].first * songs[i].second;
        song_at_moment.push_back(total_duration);
    }

    for (int i = 0; i < m; i++) {
        int moment = moments[i];
        auto it = std::lower_bound(song_at_moment.begin(), song_at_moment.end(), moment);
        int song = it - song_at_moment.begin();
        std::cout << song + 1 << std::endl;
    }

    return 0;
}