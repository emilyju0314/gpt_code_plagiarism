#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> b(n);
    for(int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    std::vector<int> p(n);

    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            p[i] = a[i];   // Use a[i] at index i to match with b[i]
        }
    }

    // Fill in the remaining elements of p
    int idx = 1;
    for(int i = 0; i < n; i++) {
        if(p[i] == 0) {
            while(std::find(p.begin(), p.end(), idx) != p.end()) {
                idx++;
            }
            p[i] = idx;
        }
    }

    for(int i = 0; i < n; i++) {
        std::cout << p[i] << " ";
    }

    return 0;
}