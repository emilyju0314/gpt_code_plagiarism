#include <iostream>
#include <vector>

int main() {
    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<std::vector<int>> grid(n, std::vector<int>(m));
    for(int i = 0; i < n; i++) {
        std::string row;
        std::cin >> row;
        for(int j = 0; j < m; j++) {
            grid[i][j] = row[j] - '0';
        }
    }

    std::vector<std::vector<int>> prefix(n + 1, std::vector<int>(m + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + grid[i-1][j-1];
        }
    }

    for(int k = 0; k < q; k++) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;

        int zeros = prefix[c][d] - prefix[a-1][d] - prefix[c][b-1] + prefix[a-1][b-1];
        int totalRectangles = (c - a + 1) * (d - b + 1);
        int goodRectangles = (totalRectangles - zeros);

        std::cout << goodRectangles << std::endl;
    }

    return 0;
}