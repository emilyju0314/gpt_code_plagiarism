#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Vector {
    int x, y, z;

    double magnitude() {
        return sqrt(x*x + y*y + z*z);
    }

    double dotProduct(const Vector& other) {
        return x*other.x + y*other.y + z*other.z;
    }

    double angle(const Vector& other) {
        double dot = dotProduct(other);
        double magProduct = magnitude() * other.magnitude();
        
        if (magProduct == 0) return 0; // handle division by zero
        
        return acos(dot / magProduct);
    }

    bool operator<(const Vector& other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return z < other.z;
    }
};

int main() {
    int m, n, S, W;
    
    while (std::cin >> m >> n >> S >> W && m != 0) {
        std::vector<Vector> vectors;
        
        for (int i = 0; i < m; ++i) {
            Vector v;
            std::cin >> v.x >> v.y >> v.z;
            vectors.push_back(v);
        }
        
        int g = S;
        for (int i = m; i < m + n; ++i) {
            Vector v;
            v.x = (g/7) % 100 + 1;
            v.y = (g/700) % 100 + 1;
            v.z = (g/70000) % 100 + 1;
            
            if (g % 2 == 0) {
                g = g / 2;
            } else {
                g = (g / 2) ^ W;
            }
            
            vectors.push_back(v);
        }
        
        Vector minVector1, minVector2;
        double minAngle = M_PI;
        
        for (int i = 0; i < vectors.size(); ++i) {
            for (int j = i + 1; j < vectors.size(); ++j) {
                double angle = vectors[i].angle(vectors[j]);
                if (angle < minAngle && angle > 0) {
                    minAngle = angle;
                    minVector1 = std::min(vectors[i], vectors[j]);
                    minVector2 = std::max(vectors[i], vectors[j]);
                }
            }
        }
        
        std::cout << minVector1.x << " " << minVector1.y << " " << minVector1.z << " "
                  << minVector2.x << " " << minVector2.y << " " << minVector2.z << std::endl;
    }
    
    return 0;
}