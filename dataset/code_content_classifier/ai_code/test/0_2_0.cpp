#include <iostream>
#include <vector>
#include <algorithm>

bool cmp(std::string a, std::string b) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (a[i] != b[i]) {
                return a[i] < b[i];
            }
        } else {
            if (a[i] != b[i]) {
                return a[i] > b[i];
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> books;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        books.push_back(s);
    }

    std::vector<int> indices(n);
    for (int i = 0; i < n; i++) {
        indices[i] = i+1;
    }

    std::sort(indices.begin(), indices.end(), [&](int a, int b) {
        return cmp(books[a-1], books[b-1]);
    });

    for (int i = 0; i < n; i++) {
        std::cout << indices[i] << " ";
    }

    return 0;
}