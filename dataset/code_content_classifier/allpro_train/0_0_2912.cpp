#include <iostream>
#include <unordered_map>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::unordered_map<std::string, std::string> serverMap;

    for (int i = 0; i < n; ++i) {
        std::string name, ip;
        std::cin >> name >> ip;
        serverMap[ip] = name;
    }

    for (int i = 0; i < m; ++i) {
        std::string command, ip;
        std::cin >> command >> ip;

        std::cout << command << " " << ip << "; #" << serverMap[ip] << std::endl;
    }

    return 0;
}