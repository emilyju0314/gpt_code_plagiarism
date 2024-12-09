#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool isRotationallyEqual(const std::string& piece1, const std::string& piece2) {
    return std::is_permutation(piece1.begin(), piece1.end(), piece2.begin());
}

bool isRotationallySymmetric(const std::string& piece) {
    std::string rotatedPiece = piece;
    for(int i = 0; i < 3; i++) {
        std::rotate(rotatedPiece.begin(), rotatedPiece.begin() + 1, rotatedPiece.end());
        if(piece == rotatedPiece) {
            return true;
        }
    }
    return false;
}

bool isValidConnection(const std::string& edge1, const std::string& edge2) {
    if((edge1 == "R" && edge2 == "r") || 
       (edge1 == "G" && edge2 == "g") ||
       (edge1 == "B" && edge2 == "b") ||
       (edge1 == "W" && edge2 == "w")) {
        return true;
    }
    return false;
}

int countSolutions(const std::vector<std::string>& puzzle) {
    std::vector<std::string> pieces = puzzle;
    std::sort(pieces.begin(), pieces.end());
    int count = 0;
    
    do {
        if((!isRotationallySymmetric(pieces[0] + pieces[1] + pieces[2] + pieces[3]) &&
            !isRotationallyEqual(pieces[0], pieces[1]) &&
            !isRotationallyEqual(pieces[0], pieces[2]) &&
            !isRotationallyEqual(pieces[1], pieces[2]) &&
            isValidConnection(pieces[0][1], pieces[1][3]) &&
            isValidConnection(pieces[0][2], pieces[2][0]) &&
            isValidConnection(pieces[1][2], pieces[3][0]) &&
            isValidConnection(pieces[2][2], pieces[3][3]))) {
            count += 1;
        }
    } while(std::next_permutation(pieces.begin(), pieces.end()));
    
    return count * 4;
}

int main() {
    int N;
    std::cin >> N;
    
    for(int i = 0; i < N; i++) {
        std::vector<std::string> puzzle(9);
        for(int j = 0; j < 9; j++) {
            std::cin >> puzzle[j];
        }
        
        int solutions = countSolutions(puzzle);
        std::cout << solutions << std::endl;
    }
    
    return 0;
}