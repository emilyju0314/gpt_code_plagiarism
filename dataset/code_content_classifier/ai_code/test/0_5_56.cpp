#include <iostream>
#include <vector>
#include <string>
#include <map>

const int MOD = 1e9 + 7;

std::map<std::string, int> colorToInt = {{"white", 0}, {"yellow", 1}, {"green", 2}, {"blue", 3}, {"red", 4}, {"orange", 5}};
std::vector<int> dp(2005, -1);

int k, n;
std::vector<std::pair<int, int>> chosenColors;

int validColorings(int node) {
    if(node >= (1 << k)) return 1;

    if(dp[node] != -1) return dp[node];

    int res = 0;
    bool possible[6] = {true, true, true, true, true, true};

    for(auto& color : chosenColors) {
        if(color.first == node) {
            possible[color.second] = false;
        }
    }

    for(int color = 0; color < 6; color++) {
        if(possible[color]) {
            res += validColorings(2 * node) * validColorings(2 * node + 1);
            res %= MOD;
        }
    }

    return dp[node] = res;
}

int main() {
    std::cin >> k >> n;

    for(int i = 0; i < n; i++) {
        int node;
        std::string color;
        std::cin >> node >> color;
        chosenColors.push_back({node, colorToInt[color]});
    }

    std::cout << validColorings(1) << std::endl;

    return 0;
}