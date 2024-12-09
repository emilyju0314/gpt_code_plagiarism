#include <iostream>
#include <vector>
#include <cmath>

struct Sphere {
    double x, y, z, r;
};

struct Ray {
    double u, v, w;
};

struct Point {
    double x, y, z;
};

Point intersect(const Point& I, const Point& Q, double r) {
    double d = sqrt((Q.x - I.x) * (Q.x - I.x) + (Q.y - I.y) * (Q.y - I.y) + (Q.z - I.z) * (Q.z - I.z));
    double t = r / d;
    return {I.x + t * (Q.x - I.x), I.y + t * (Q.y - I.y), I.z + t * (Q.z - I.z)};
}

Point reflect(const Point& I, const Point& Q, const Point& N) {
    double qx = Q.x - I.x;
    double qy = Q.y - I.y;
    double qz = Q.z - I.z;
    
    double nx = N.x - Q.x;
    double ny = N.y - Q.y;
    double nz = N.z - Q.z;
    
    double dot = qx * nx + qy * ny + qz * nz;
    
    double rx = qx - 2 * dot * nx;
    double ry = qy - 2 * dot * ny;
    double rz = qz - 2 * dot * nz;
    
    Point R = {Q.x + rx, Q.y + ry, Q.z + rz};
    
    return R;
}

int main() {
    int N;
    while (std::cin >> N && N != 0) {
        Ray ray;
        std::cin >> ray.u >> ray.v >> ray.w;
        
        std::vector<Sphere> spheres(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> spheres[i].x >> spheres[i].y >> spheres[i].z >> spheres[i].r;
        }
        
        Point I = {0, 0, 0};
        
        for (const auto& sphere : spheres) {
            Point Q = intersect(I, {ray.u, ray.v, ray.w}, sphere.r);
            Point N = {sphere.x, sphere.y, sphere.z};
            Point R = reflect(I, Q, N);
            
            I = R;
        }
        
        std::cout << std::fixed;
        std::cout.precision(4);
        std::cout << I.x << " " << I.y << " " << I.z << std::endl;
    }
    
    return 0;
}