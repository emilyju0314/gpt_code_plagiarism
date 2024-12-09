#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

double cross_product(Point A, Point B, Point C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

int main() {
    vector<Point> S, T;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        Point p;
        cin >> p.x >> p.y;
        S.push_back(p);
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        Point p;
        cin >> p.x >> p.y;
        T.push_back(p);
    }

    cout << fixed << setprecision(10);

    if (n > 4) {
        cout << "scissors" << endl << "0 " << n / 2 << endl;
        for (int i = 0; i < n / 2; i++) {
            cout << "4 ";
            for (int j = i * 2; j < i * 2 + 4; j++) {
                cout << S[j].x << " " << S[j].y << " ";
            }
            cout << endl;
        }

        cout << "tape" << endl << n / 2 << " 1";
        for (int i = 0; i < n / 2; i++) {
            cout << " " << i + 2;
        }
        cout << endl;

        cout << "4 ";
        for (int i = 0; i < 4; i++) {
            cout << T[i].x << " " << T[i].y << " ";
        }
        cout << endl;

    } else {
        cout << "scissors" << endl << "0 2" << endl;
        for (int i = 0; i < 2; i++) {
            cout << "4 ";
            for (int j = i * 2; j < i * 2 + 4; j++) {
                cout << S[j].x << " " << S[j].y << " ";
            }
            cout << endl;
        }

        cout << "tape" << endl << "2 1 2" << endl;
        cout << "4 ";
        for (int i = 0; i < 4; i++) {
            cout << T[i].x << " " << T[i].y << " ";
        }
        cout << endl;
    }

    return 0;
}