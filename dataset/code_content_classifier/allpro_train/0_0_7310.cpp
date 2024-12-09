#include <iostream>
#include <algorithm>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    if (k > n + m - 2) {
        std::cout << "-1" << std::endl;
    } else {
        int cuts_horiz = std::min(n-1, k);
        int cuts_vert = std::min(m-1, k-cuts_horiz);

        // Calculate the number of pieces after making cuts
        int pieces_horiz = cuts_horiz + 1;
        int pieces_vert = cuts_vert + 1;

        // Calculate the maximum area of the smallest piece
        int max_area = (n / pieces_horiz) * (m / pieces_vert);

        std::cout << max_area << std::endl;
    }

    return 0;
}