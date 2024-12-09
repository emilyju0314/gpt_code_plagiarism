#include <iostream>
#include <set>

int main() {
    int n, m;
    std::set<int> A, B, union_set;

    // Input set A
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        A.insert(num);
    }

    // Input set B
    std::cin >> m;
    for(int i = 0; i < m; i++) {
        int num;
        std::cin >> num;
        B.insert(num);
    }

    // Find the union of sets A and B
    for(auto it = A.begin(); it != A.end(); it++) {
        union_set.insert(*it);
    }
    for(auto it = B.begin(); it != B.end(); it++) {
        union_set.insert(*it);
    }

    // Output the union set in ascending order
    for(auto it = union_set.begin(); it != union_set.end(); it++) {
        std::cout << *it << std::endl;
    }

    return 0;
}