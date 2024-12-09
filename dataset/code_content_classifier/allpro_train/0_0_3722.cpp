#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Ball {
    double x, y;
    double vx, vy;
    double r;
};

struct Collision {
    int index;
    double time;
};

const double EPS = 1e-9;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

Collision getCollisionTime(Ball hitBall, Ball otherBall) {
    double dx = otherBall.x - hitBall.x;
    double dy = otherBall.y - hitBall.y;
    double dvx = otherBall.vx - hitBall.vx;
    double dvy = otherBall.vy - hitBall.vy;
    double dr = hitBall.r + otherBall.r;

    double a = dvx*dvx + dvy*dvy;
    double b = 2 * (dx*dvx + dy*dvy);
    double c = dx*dx + dy*dy - dr*dr;

    double disc = b*b - 4*a*c;
    if (disc < 0) {
        return {-1, -1};
    }

    double t1 = (-b + sqrt(disc))/(2*a);
    double t2 = (-b - sqrt(disc))/(2*a);

    double time = min(t1, t2);
    if (time < 0) {
        return {-1, -1};
    }

    return {otherBall.index, time};
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<Ball> balls(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            balls[i] = {x, y, 0, 0, 0, i+1};
        }

        int w, h, r, vx, vy;
        cin >> w >> h >> r >> vx >> vy;
        Ball hitBall = {r, r, vx, vy, r};

        bool collided = false;
        int collisionIndex = -1;
        double time = 0;

        while (!collided) {
            Collision firstCollision = {n+1, 1e9};
            for (int i = 0; i < n; i++) {
                Ball currentBall = balls[i];
                if (currentBall.vx == 0 && currentBall.vy == 0) continue;

                Collision currentCollision = getCollisionTime(hitBall, currentBall);
                if (currentCollision.time < firstCollision.time) {
                    firstCollision = currentCollision;
                    collisionIndex = i;
                }
            }

            if (firstCollision.time == -1) {
                break;
            }

            time += firstCollision.time;
            hitBall.x += hitBall.vx * firstCollision.time;
            hitBall.y += hitBall.vy * firstCollision.time;

            if (firstCollision.index == -1) {
                break;
            } else {
                Ball collidedBall = balls[firstCollision.index];
                double dx = collidedBall.x - hitBall.x;
                double dy = collidedBall.y - hitBall.y;
                double dist = sqrt(dx*dx + dy*dy);

                double nx = dx / dist;
                double ny = dy / dist;
                
                double dp = hitBall.vx*nx + hitBall.vy*ny;
                hitBall.vx -= 2 * dp * nx;
                hitBall.vy -= 2 * dp * ny;

                double dvx = hitBall.vx - collidedBall.vx;
                double dvy = hitBall.vy - collidedBall.vy;
                double mag = sqrt(dvx*dvx + dvy*dvy);

                hitBall.vx = collidedBall.vx + dvx / mag;
                hitBall.vy = collidedBall.vy + dvy / mag;
            }
        }

        if (collisionIndex == -1) {
            cout << -1 << endl;
        } else {
            cout << collisionIndex+1 << endl;
        }
    }

    return 0;
}