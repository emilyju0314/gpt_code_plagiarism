#include <iostream>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;

    std::unordered_map<int, int> likes;
    int max_likes = 0;
    int winner = 0;

    for (int i = 0; i < n; i++) {
        int photo_id;
        std::cin >> photo_id;

        likes[photo_id]++;
        if (likes[photo_id] >= max_likes) {
            max_likes = likes[photo_id];
            winner = photo_id;
        }
    }

    std::cout << winner << std::endl;

    return 0;
}