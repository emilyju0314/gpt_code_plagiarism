#include <iostream>
#include <sstream>
#include <cmath>

class Point {
public:
    double x, y;
    
    Point(double x, double y): x(x), y(y) {}
    
    Point symmetricalWithRespectToLine(Line line) {
        double v1 = line.p2.x - line.p1.x;
        double v2 = line.p2.y - line.p1.y;
        double L = sqrt(pow(v1, 2) + pow(v2, 2));
        double newX = x - 2 * (v1 * (v1 * (x - line.p1.x) + v2 * (y - line.p1.y)) / pow(L, 2));
        double newY = y - 2 * (v2 * (v1 * (x - line.p1.x) + v2 * (y - line.p1.y)) / pow(L, 2));
        
        return Point(newX, newY);
    }
    
    double distanceTo(Point p) {
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }
};

class Line {
public:
    Point p1, p2;
    
    Line(Point p1, Point p2): p1(p1), p2(p2) {}
    
    Point intersectionWithLine(Line other) {
        double A1 = p2.y - p1.y;
        double B1 = p1.x - p2.x;
        double C1 = A1 * p1.x + B1 * p1.y;
        
        double A2 = other.p2.y - other.p1.y;
        double B2 = other.p1.x - other.p2.x;
        double C2 = A2 * other.p1.x + B2 * other.p1.y;
        
        double det = A1 * B2 - A2 * B1;
        double x = (B2 * C1 - B1 * C2) / det;
        double y = (A1 * C2 - A2 * C1) / det;
        
        return Point(x, y);
    }
};

Point evaluateExpression(std::istringstream& expression) {
    char operation;
    expression >> operation;
    if (operation == '(') {
        double x, y;
        expression >> x; // Read x-coordinate
        expression.ignore(); // Ignore the comma
        expression >> y; // Read y-coordinate
        return Point(x, y);
    } else {
        Point p1 = evaluateExpression(expression);
        Point p2 = evaluateExpression(expression);
        
        if (operation == '@') {
            if (expression.peek() == '(') {
                expression.get(); // Consume the opening parenthesis
                Point p3 = evaluateExpression(expression);
                return p1.symmetricalWithRespectToLine(Line(p2, p3));
            } else {
                return Line(p1, p2).intersectionWithLine(Line(p2, evaluateExpression(expression)));
            }
        }
    }
    
    return Point(0, 0); // Dummy return value
}

int main() {
    std::string input;
    while (getline(std::cin, input) && input != "#") {
        std::istringstream iss(input);
        Point treasure = evaluateExpression(iss);
        std::cout << treasure.x << " " << treasure.y << std::endl;
    }
    
    return 0;
}