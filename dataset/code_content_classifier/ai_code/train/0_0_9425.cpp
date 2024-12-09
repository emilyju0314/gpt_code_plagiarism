#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isTemplateContained(vector<string>& image, vector<string>& templateImage) {
    int n = image.size();
    int m = templateImage.size();
    
    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j <= n - m; j++) {
            bool match = true;
            for (int k = 0; k < m; k++) {
                for (int l = 0; l < m; l++) {
                    if (image[i+k][j+l] != templateImage[k][l]) {
                        match = false;
                        break;
                    }
                }
                if (!match) break;
            }
            if (match) return true;
        }
    }
    
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> image(n), templateImage(m);
    for (int i = 0; i < n; i++) {
        cin >> image[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> templateImage[i];
    }
    
    if (isTemplateContained(image, templateImage)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}