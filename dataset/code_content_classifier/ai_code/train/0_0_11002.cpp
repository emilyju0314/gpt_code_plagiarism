#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::unordered_set<int> niceIndices;

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < n; j++) {
            if(j == i) continue;
            sum += a[j];
        }

        for(int j = 0; j < n; j++) {
            if(j == i) continue;
            if(a[j] == sum) {
                niceIndices.insert(i+1);
                break;
            }
        }
    }

    std::cout << niceIndices.size() << std::endl;
    for(auto index : niceIndices) {
        std::cout << index << " ";
    }

    return 0;
}