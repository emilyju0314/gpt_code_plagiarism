#include <iostream>
#include <map>
#include <cmath>
#include <iomanip>

int main() {
    int n, m;
    double k;
    std::cin >> n >> m >> k;

    std::map<std::string, int> skills;
    for(int i=0; i<n; i++) {
        std::string name;
        int exp;
        std::cin >> name >> exp;
        skills[name] = exp;
    }

    for(int i=0; i<m; i++) {
        std::string name;
        std::cin >> name;
        skills[name] = 0;
    }

    for(auto it=skills.begin(); it!=skills.end(); it++) {
        it->second = std::max(0, (int)std::floor(k*it->second));
        if(it->second < 100) {
            skills.erase(it);
        }
    }

    std::cout << skills.size() << std::endl;
    for(auto it=skills.begin(); it!=skills.end(); it++) {
        std::cout << it->first << " " << it->second << std::endl;
    }

    return 0;
}