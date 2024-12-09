#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        
        unordered_set<string> unique_cubes;
        int additional_works = 0;
        
        for (int i = 0; i < n; i++) {
            string cube_colors = "";
            for (int j = 0; j < 6; j++) {
                string color;
                cin >> color;
                cube_colors += color;
            }
            if (unique_cubes.find(cube_colors) == unique_cubes.end()) {
                unique_cubes.insert(cube_colors);
            } else {
                additional_works++;
            }
        }
        
        cout << additional_works << endl;
    }
    
    return 0;
}