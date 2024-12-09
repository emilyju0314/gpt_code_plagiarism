#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct Point {
    int x, y, z;

    Point(int x, int y, int z) : x(x), y(y), z(z) {}
};

bool sameKey(vector<string>& description1, vector<string>& description2) {
    vector<Point> path1, path2;
    unordered_map<int, Point> labels1, labels2;

    Point current1(0, 0, 0), current2(0, 0, 0);

    for (size_t i = 0; i < description1.size(); i++) {
        if (description1[i] == "+x") {
            current1.x++;
        } else if (description1[i] == "-x") {
            current1.x--;
        } else if (description1[i] == "+y") {
            current1.y++;
        } else if (description1[i] == "-y") {
            current1.y--;
        } else if (description1[i] == "+z") {
            current1.z++;
        } else if (description1[i] == "-z") {
            current1.z--;
        } else {
            int label = stoi(description1[i]);
            labels1[label] = current1;
        }
        path1.push_back(current1);
    }

    for (size_t i = 0; i < description2.size(); i++) {
        if (description2[i] == "+x") {
            current2.x++;
        } else if (description2[i] == "-x") {
            current2.x--;
        } else if (description2[i] == "+y") {
            current2.y++;
        } else if (description2[i] == "-y") {
            current2.y--;
        } else if (description2[i] == "+z") {
            current2.z++;
        } else if (description2[i] == "-z") {
            current2.z--;
        } else {
            int label = stoi(description2[i]);
            labels2[label] = current2;
        }
        path2.push_back(current2);
    }

    if (path1.size() != path2.size()) {
        return false;
    }

    for (size_t i = 0; i < path1.size(); i++) {
        if (path1[i].x != path2[i].x || path1[i].y != path2[i].y || path1[i].z != path2[i].z) {
            return false;
        }
    }

    for (const auto& label : labels1) {
        if (labels2.find(label.first) == labels2.end() || labels1[label.first].x != labels2[label.first].x || labels1[label.first].y != labels2[label.first].y || labels1[label.first].z != labels2[label.first].z) {
            return false;
        }
    }

    for (const auto& label : labels2) {
        if (labels1.find(label.first) == labels1.end() || labels2[label.first].x != labels1[label.first].x || labels2[label.first].y != labels1[label.first].y || labels2[label.first].z != labels1[label.first].z) {
            return false;
        }
    }

    return true;
}

int main() {
    while(true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }

        vector<string> description1, description2;

        for (int i = 0; i < n; i++) {
            string element;
            cin >> element;
            description1.push_back(element);
        }

        for (int i = 0; i < n; i++) {
            string element;
            cin >> element;
            description2.push_back(element);
        }

        if (sameKey(description1, description2)) {
            cout << "SAME" << endl;
        } else {
            cout << "DIFFERENT" << endl;
        }
    }

    return 0;
}
}