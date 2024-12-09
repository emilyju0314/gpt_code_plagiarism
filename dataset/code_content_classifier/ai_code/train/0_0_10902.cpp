#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::string getParentDirectory(const std::string& path) {
    size_t pos = path.find_last_of('/');
    return path.substr(0, pos);
}

bool areAliases(const std::string& path1, const std::string& path2, const std::unordered_map<std::string, bool>& webPages) {
    std::string canonicalPath1 = path1;
    std::string canonicalPath2 = path2;

    while(canonicalPath1 != canonicalPath2) {
        if(webPages.find(canonicalPath1) == webPages.end() || webPages.find(canonicalPath2) == webPages.end()) {
            return false;
        }

        std::string parent1 = getParentDirectory(canonicalPath1);
        std::string parent2 = getParentDirectory(canonicalPath2);

        if(parent1 == parent2) {
            break;
        }

        if(webPages.find(parent1) == webPages.end() || webPages.find(parent2) == webPages.end()) {
            return false;
        }

        canonicalPath1 = parent1;
        canonicalPath2 = parent2;
    }

    return true;
}

int main() {
    int N, M;
    while(std::cin >> N >> M) {
        if(N == 0 && M == 0) {
            break;
        }

        std::unordered_map<std::string, bool> webPages;
        for(int i = 0; i < N; ++i) {
            std::string path;
            std::cin >> path;
            webPages[path] = true;
        }

        for(int i = 0; i < M; ++i) {
            std::string path1, path2;
            std::cin >> path1 >> path2;
            if(areAliases(path1, path2, webPages)) {
                std::cout << "yes" << std::endl;
            } else if(webPages.find(path1) == webPages.end() || webPages.find(path2) == webPages.end()) {
                std::cout << "not found" << std::endl;
            } else {
                std::cout << "no" << std::endl;
            }
        }
    }

    return 0;
}