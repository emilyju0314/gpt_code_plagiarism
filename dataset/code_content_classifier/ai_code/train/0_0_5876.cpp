#include <iostream>
#include <vector>
#include <cmath>

struct Sphere {
    int x, y, z, r;
};

bool areSpheresIntersecting(const Sphere& s1, const Sphere& s2) {
    int distSq = pow(s1.x - s2.x, 2) + pow(s1.y - s2.y, 2) + pow(s1.z - s2.z, 2);
    int radiusSumSq = pow(s1.r + s2.r, 2);
    return distSq <= radiusSumSq;
}

int countConnectedComponents(const std::vector<Sphere>& spheres, double z) {
    int count = 0;
    std::vector<int> visited(spheres.size(), 0);
    
    for (int i = 0; i < spheres.size(); i++) {
        if (spheres[i].z - spheres[i].r <= z && spheres[i].z + spheres[i].r >= z && visited[i] == 0) {
            count++;
            visited[i] = 1;
            for (int j = i+1; j < spheres.size(); j++) {
                if (areSpheresIntersecting(spheres[i], spheres[j])) {
                    visited[j] = 1;
                }
            }
        }
    }
    
    return count;
}

int main() {
    int N;
    while (std::cin >> N && N != 0) {
        std::vector<Sphere> spheres(N);
        for (int i = 0; i < N; i++) {
            std::cin >> spheres[i].x >> spheres[i].y >> spheres[i].z >> spheres[i].r;
        }
        
        int prevConnectedComponents = 0;
        std::string transitions;
        for (int z = 0; z <= 36000; z++) {
            int connectedComponents = countConnectedComponents(spheres, z);
            if (prevConnectedComponents < connectedComponents) {
                transitions += '1';
            } else if (prevConnectedComponents > connectedComponents) {
                transitions += '0';
            }
            prevConnectedComponents = connectedComponents;
        }
        
        std::cout << transitions.size() << std::endl;
        std::cout << transitions << std::endl;
    }
    
    return 0;
}