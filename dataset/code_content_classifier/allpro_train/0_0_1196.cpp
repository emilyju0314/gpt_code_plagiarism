#include <iostream>
#include <map>
#include <string>

int main() {
    int N;
    std::cin >> N;
    
    std::map<std::string, int> songs;
    for (int i = 0; i < N; i++) {
        std::string title;
        int duration;
        std::cin >> title >> duration;
        songs[title] = duration;
    }
    
    std::string X;
    std::cin >> X;
    
    bool found = false;
    int total_duration = 0;
    for (auto it = songs.begin(); it != songs.end(); it++) {
        if (found) {
            total_duration += it->second;
        }
        if (it->first == X) {
            found = true;
            total_duration += it->second;
        }
    }
    
    std::cout << total_duration << std::endl;
    
    return 0;
}