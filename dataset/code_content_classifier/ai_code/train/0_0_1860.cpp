#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    vector<string> picture(A);
    for(int i = 0; i < A; i++) {
        cin >> picture[i];
    }

    set<pair<int, int>> validPuzzles;
    int minArea = A * B;

    for(int i = 1; i <= A; i++) {
        if(A % i == 0) {
            for(int j = 1; j <= B; j++) {
                if(B % j == 0) {
                    set<string> puzzleSet;
                    bool valid = true;
                    int area = i * j;

                    for(int x = 0; x < A; x += i) {
                        for(int y = 0; y < B; y += j) {
                            string piece = "";
                            for(int k = x; k < x + i; k++) {
                                piece += picture[k].substr(y, j);
                            }
                            if(puzzleSet.count(piece) > 0) {
                                valid = false;
                                break;
                            } else {
                                puzzleSet.insert(piece);
                            }
                        }
                        if(!valid) break;
                    }

                    if(valid) {
                        if(area < minArea) {
                            minArea = area;
                        }
                        validPuzzles.insert({i, j});
                    }
                }
            }
        }
    }

    cout << validPuzzles.size() << endl;
    cout << validPuzzles.begin()->first << " " << validPuzzles.begin()->second << endl;

    return 0;
}