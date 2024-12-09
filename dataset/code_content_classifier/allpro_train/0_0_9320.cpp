#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> faces = {
        {"Tetrahedron", 4},
        {"Cube", 6},
        {"Octahedron", 8},
        {"Dodecahedron", 12},
        {"Icosahedron", 20}
    };

    int n;
    std::cin >> n;

    int total_faces = 0;
    for (int i = 0; i < n; i++) {
        std::string polyhedron;
        std::cin >> polyhedron;
        total_faces += faces[polyhedron];
    }

    std::cout << total_faces << std::endl;

    return 0;
}