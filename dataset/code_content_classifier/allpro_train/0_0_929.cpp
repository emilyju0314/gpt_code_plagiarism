#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Line {
    int start, end, y;
};

long long int calculate_area(vector<Line>& horizontal_lines, vector<Line>& vertical_lines) {
    long long int area = 0;
    for(auto& h_line : horizontal_lines) {
        for(auto& v_line : vertical_lines) {
            long long int width = v_line.end - v_line.start;
            long long int height = h_line.y - v_line.y;
            area += width * height;
        }
    }
    return area;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Line> horizontal_lines(N);
    vector<Line> vertical_lines(M);

    for(int i = 0; i < N; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        horizontal_lines[i] = {A, B, C};
    }

    for(int i = 0; i < M; i++) {
        int D, E, F;
        cin >> D >> E >> F;
        vertical_lines[i] = {E, F, D};
    }

    sort(horizontal_lines.begin(), horizontal_lines.end(), [](const Line& a, const Line& b) {
        return a.y < b.y;
    });

    sort(vertical_lines.begin(), vertical_lines.end(), [](const Line& a, const Line& b) {
        return a.y < b.y;
    });

    long long int area = calculate_area(horizontal_lines, vertical_lines);

    if(area >= 2e9) {
        cout << "INF" << endl;
    } else {
        cout << area << endl;
    }

    return 0;
}