#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Piece {
    int width, depth;
};

bool sortPieces(const Piece& p1, const Piece& p2) {
    return (p1.width * p1.depth) < (p2.width * p2.depth);
}

int main() {
    int n, w, d;
    
    while (cin >> n >> w >> d) {
        if (n == 0 && w == 0 && d == 0) break;
        
        vector<Piece> pieces;
        Piece initialPiece = {w, d};
        pieces.push_back(initialPiece);
        
        for (int i = 0; i < n; i++) {
            int targetPiece, cutSize;
            cin >> targetPiece >> cutSize;
            
            Piece cutPiece = pieces[targetPiece-1];
            pieces.erase(pieces.begin() + targetPiece - 1);
            
            if (cutPiece.width > cutPiece.depth) {
                Piece newPiece1 = {cutSize, cutPiece.depth};
                Piece newPiece2 = {cutPiece.width - cutSize, cutPiece.depth};
                pieces.push_back(newPiece1);
                pieces.push_back(newPiece2);
            } else {
                Piece newPiece1 = {cutPiece.width, cutSize};
                Piece newPiece2 = {cutPiece.width, cutPiece.depth - cutSize};
                pieces.push_back(newPiece1);
                pieces.push_back(newPiece2);
            }
            
            sort(pieces.begin(), pieces.end(), sortPieces);
        }
        
        for (const auto& piece : pieces) {
            cout << (piece.width * piece.depth) << " ";
        }
        cout << endl;
    }
    
    return 0;
}