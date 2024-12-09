#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define N 500001

class Node {
    public:
        int location;
        int l, r;
        Node() {}
};

class Point {
    public:
        int id, x, y;
        Point() {}
        Point(int id, int x, int y): id(id), x(x), y(y) {}
        bool operator < (const Point &p) const {
            return id < p.id;
        }
        
        void print() {
            printf("%d\n", id);
        }
};

Point P[N];
Node T[N];
int np;
vector<Point> ans;
int NIL = -1;

bool lessX(const Point &p1, const Point &p2) {
    return p1.x < p2.x;
}
bool lessY(const Point &p1, const Point &p2) {
    return p1.y < p2.y;
}

int buildKDtree(int l, int r, int depth) {
    if (l >= r) {
        return NIL;
    }

    int mid = (l + r) / 2;
    if (depth % 2 == 0) {
        sort(P + l, P + r, lessX);
    } else {
        sort(P + l, P + r, lessY);
    }

    int t = np++;
    T[t].location = mid;
    T[t].l = buildKDtree(l, mid, depth + 1);
    T[t].r = buildKDtree(mid + 1, r, depth + 1);
    
    return t;
}

void find(int v, int sx, int tx, int sy, int ty, int depth) {
    int x = P[T[v].location].x;
    int y = P[T[v].location].y;

    if (x >= sx && x <= tx && y >= sy && y <= ty) {
        ans.push_back(P[T[v].location]);
    }

    if (depth % 2 == 0) {
        if (T[v].l != NIL) {
            if (x >= sx) {
                find(T[v].l, sx, tx, sy, ty, depth + 1);
            }
        }

        if (T[v].r != NIL) {
            if (x <= tx) {
                find(T[v].r, sx, tx, sy, ty, depth + 1);
            }
        }
    } else {
        if (T[v].l != NIL) {
            if (y >= sy) {
                find(T[v].l, sx, tx, sy, ty, depth + 1);
            }
        }

        if (T[v].r != NIL) {
            if (y <= ty) {
                find(T[v].r, sx, tx, sy, ty, depth + 1);
            }
        }
    }
}

int main() {
    int n, q;
    cin >> n;

    np = 0;

    int id, x, y;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        P[i] = Point(i, x, y);
    }

    buildKDtree(0, n, 0);

    cin >> q;
    int sx, tx, sy, ty;
    for (int i = 0; i < q; i++) {
        ans.clear();
        scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
        find(0, sx, tx, sy, ty, 0);
        sort(ans.begin(), ans.end());
        for (int j = 0; j < ans.size(); j++) {
            ans[j].print();
        }
        printf("\n");
    }

    return 0;
}

