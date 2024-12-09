#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> planes(m);
    for(int i = 0; i < m; i++) {
        std::cin >> planes[i];
    }
    
    int minSum = 0, maxSum = 0;
    std::sort(planes.begin(), planes.end());
    
    int remainingSeats = n;
    
    for(int i = 0; i < n; i++) {
        minSum += planes[0];
        planes[0]--;
        if(planes[0] == 0) {
            planes.erase(planes.begin());
            m--;
        }
    }
    
    planes = std::vector<int>(m);
    for(int i = 0; i < m; i++) {
        planes[i] = n;
    }
    
    for(int i = 0; i < n; i++) {
        maxSum += planes.back();
        planes[m-1]--;
        if(planes[m-1] == 0) {
            planes.erase(planes.end()-1);
            m--;
        }
    }
    
    std::cout << maxSum << " " << minSum << std::endl;
    
    return 0;
}