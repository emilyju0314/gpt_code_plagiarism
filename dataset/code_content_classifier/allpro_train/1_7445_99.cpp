#include<iostream>
#include<iomanip>
using namespace std;

struct Point{
    double x;
    double y;
    Point(double x, double y) : x(x), y(y){}
    Point operator+(Point p){
        return Point(x + p.x, y + p.y);
    }
    Point operator*(double d){
        return Point(x * d, y * d);
    }
};
typedef Point Vector;

double dot(Vector v1, Vector v2){
    return v1.x * v2.x + v1.y * v2.y;
}

int main(){
    int x_p1, y_p1, x_p2, y_p2;
    cin >> x_p1 >> y_p1 >> x_p2 >> y_p2;
    Point p1(x_p1, y_p1);
    Point p2(x_p2, y_p2);
    Vector b(p2.x - p1.x, p2.y - p1.y);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        Vector h(x - p1.x, y - p1.y);
        Point ans = p1 + b * (dot(h, b) / dot(b, b));
        cout << fixed << setprecision(10);
        cout << ans.x << " " << ans.y << endl;
    }
    return 0;
}

