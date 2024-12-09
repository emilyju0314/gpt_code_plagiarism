#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> p(n);
    std::vector<int> a(n);
    std::vector<int> s(n);

    for(int i = 0; i < n; i++) {
        a[i] = i+1;
    }

    for(int i = 0; i < 2*n; i++) {
        std::cout << "?";
        for(int j = 0; j < n; j++) {
            std::cout << " " << a[j];
        }
        std::cout << std::endl;
        std::cout.flush();

        int k;
        std::cin >> k;
        if(k == 0) continue;
        else {
            s[k-1]++;
            if(s[k-1] == 2) {
                std::cout << "!";
                for(int j = 0; j < n; j++) {
                    std::cout << " " << p[j];
                }
                std::cout << std::endl;
                break;
            }
        }

        std::next_permutation(a.begin(), a.end());
    }

    return 0;
}