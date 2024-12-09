#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Star {
    int x, y, index;
};

int orientation(Star a, Star b, Star c) {
    int val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    
    if(val == 0) {
        return 0;
    } else {
        return (val > 0) ? 1 : 2;
    }
}

bool compareStars(Star a, Star b) {
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

int main() {
    int n;
    cin >> n;
    
    vector<Star> stars(n);
    for(int i = 0; i < n; i++) {
        cin >> stars[i].x >> stars[i].y;
        stars[i].index = i + 1;
    }
    
    sort(stars.begin(), stars.end(), compareStars);
    
    Star a = stars[0], b = stars[1], c = stars[2];
    
    for(int i = 3; i < n; i++) {
        while(orientation(a, b, c) == 0 && i < n) {
            c = stars[i];
            i++;
        }
        
        if(i == n) {
            break;
        }
        
        if(orientation(a, b, c) == 1) {
            swap(a, c);
        } else if(orientation(a, b, c) == 2) {
            break;
        }
    }
    
    cout << a.index << " " << b.index << " " << c.index << endl;
    
    return 0;
}