#include <iostream>
#include <map>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::map<std::string, int> repostChainLength;
    repostChainLength["polycarp"] = 1;

    int maxChainLength = 1;

    for (int i = 0; i < n; ++i) {
        std::string name1, reposted, name2;
        std::cin >> name1 >> reposted >> name2;

        std::transform(name1.begin(), name1.end(), name1.begin(), ::tolower);
        std::transform(name2.begin(), name2.end(), name2.begin(), ::tolower);

        repostChainLength[name1] = repostChainLength[name2] + 1;
        maxChainLength = std::max(maxChainLength, repostChainLength[name1]);
    }

    std::cout << maxChainLength << std::endl;

    return 0;
}