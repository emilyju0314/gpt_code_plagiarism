#include <iostream>
#include <vector>
#include <algorithm>

bool compare(std::string a, std::string b) {
    for(int i = 0; i < a.length(); i++) {
        if(i % 2 == 0) {
            if(a[i] < b[i]) {
                return true;
            }
            else if(a[i] > b[i]) {
                return false;
            }
        }
        else {
            if(a[i] > b[i]) {
                return true;
            }
            else if(a[i] < b[i]) {
                return false;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::string> books(n);
    for(int i = 0; i < n; i++) {
        std::cin >> books[i];
    }
    
    std::vector<int> indices(n);
    for(int i = 0; i < n; i++) {
        indices[i] = i+1;
    }
    
    std::sort(indices.begin(), indices.end(), [&](int a, int b) {
        return compare(books[a-1], books[b-1]);
    });
    
    for(int i = 0; i < n; i++) {
        std::cout << indices[i] << " ";
    }

    return 0;
}