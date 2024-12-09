#include <iostream>
#include <vector>
#include <algorithm>

struct Request {
    int k;
    int pos;
};

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int m;
    std::cin >> m;

    std::vector<Request> requests(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> requests[i].k >> requests[i].pos;
    }

    for (const auto& request : requests) {
        std::vector<int> indexes(n);
        std::iota(indexes.begin(), indexes.end(), 0);

        std::sort(indexes.begin(), indexes.end(), [&a](int i, int j) {
            if (a[i] == a[j]) {
                return i < j;
            }
            return a[i] > a[j];
        });

        std::vector<bool> taken(n);
        std::vector<int> result;
        for (int i = 0; i < request.k; ++i) {
            taken[indexes[i]] = true;
            result.push_back(a[indexes[i]]);
        }

        std::sort(result.begin(), result.end());

        std::cout << result[request.pos - 1] << std::endl;
    }

    return 0;
}