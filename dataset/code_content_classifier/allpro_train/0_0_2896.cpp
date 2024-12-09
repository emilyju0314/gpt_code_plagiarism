#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countFaces(vector<string>& image) {
    int n = image.size();
    int m = image[0].size();
    int count = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (image[i][j] == 'f' && image[i][j + 1] == 'a' && image[i + 1][j] == 'c' && image[i + 1][j + 1] == 'e') {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> image(n);
    for (int i = 0; i < n; i++) {
        cin >> image[i];
    }

    cout << countFaces(image) << endl;

    return 0;
}