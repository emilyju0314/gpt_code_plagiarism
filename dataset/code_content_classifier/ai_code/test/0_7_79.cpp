#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<int> b(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    std::vector<int> jumps(n, -1);
    jumps[0] = 0;

    for (int i = 0; i < n; ++i) {
        if (jumps[i] == -1) {
            continue;
        }

        for (int j = a[i]; j >= 0; --j) {
            if (i+j >= n) {
                continue;
            }

            if (jumps[i+j] == -1 || jumps[i+j] > jumps[i] + 1) {
                jumps[i+j] = jumps[i] + 1;
            }
        }
    }

    if (jumps[n-1] == -1) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << jumps[n-1] << std::endl;
        std::vector<int> path;
        int current_height = n-1;
        while (current_height > 0) {
            for (int j = a[current_height]; j >= 0; --j) {
                if (current_height-j >= 0 && jumps[current_height-j] == jumps[current_height] - 1) {
                    path.push_back(current_height);
                    current_height -= j;
                    break;
                }
            }
        }
        path.push_back(0);
        
        for (int i = path.size()-1; i >= 0; --i) {
            std::cout << path[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}